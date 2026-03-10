//
// DOG — Difference of Gaussians
// cavriley, ECE:5490 HW04
//
#include <iostream>
#include "itkCastImageFilter.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkRecursiveGaussianImageFilter.h"
#include "itkRescaleIntensityImageFilter.h"
#include "itkSubtractImageFilter.h"
#include "DOGCLP.h"

int main(int argc, char * argv[])
{
  PARSE_ARGS;

  using InputImageType = itk::Image<short, 3>;
  using RealImageType = itk::Image<float, 3>;
  using OutputImageType = itk::Image<unsigned char, 3>;

  using ReaderType = itk::ImageFileReader<InputImageType>;
  using CastType = itk::CastImageFilter<InputImageType, RealImageType>;
  using GaussianType = itk::RecursiveGaussianImageFilter<RealImageType, RealImageType>;
  using SubtractType = itk::SubtractImageFilter<RealImageType, RealImageType, RealImageType>;
  using RescaleType = itk::RescaleIntensityImageFilter<RealImageType, OutputImageType>;
  using WriterType = itk::ImageFileWriter<OutputImageType>;

  try
  {
    auto reader = ReaderType::New();
    reader->SetFileName(input);

    auto caster = CastType::New();
    caster->SetInput(reader->GetOutput());

    // Gaussian chain 1 — sigma1
    auto g1x = GaussianType::New();
    g1x->SetInput(caster->GetOutput());
    g1x->SetSigma(sigma1);
    g1x->SetDirection(0);
    g1x->SetNormalizeAcrossScale(false);

    auto g1y = GaussianType::New();
    g1y->SetInput(g1x->GetOutput());
    g1y->SetSigma(sigma1);
    g1y->SetDirection(1);
    g1y->SetNormalizeAcrossScale(false);

    auto g1z = GaussianType::New();
    g1z->SetInput(g1y->GetOutput());
    g1z->SetSigma(sigma1);
    g1z->SetDirection(2);
    g1z->SetNormalizeAcrossScale(false);

    // Gaussian chain 2 — sigma2
    auto g2x = GaussianType::New();
    g2x->SetInput(caster->GetOutput());
    g2x->SetSigma(sigma2);
    g2x->SetDirection(0);
    g2x->SetNormalizeAcrossScale(false);

    auto g2y = GaussianType::New();
    g2y->SetInput(g2x->GetOutput());
    g2y->SetSigma(sigma2);
    g2y->SetDirection(1);
    g2y->SetNormalizeAcrossScale(false);

    auto g2z = GaussianType::New();
    g2z->SetInput(g2y->GetOutput());
    g2z->SetSigma(sigma2);
    g2z->SetDirection(2);
    g2z->SetNormalizeAcrossScale(false);

    // DOG = G(sigma1) - G(sigma2)
    auto subtract = SubtractType::New();
    subtract->SetInput1(g1z->GetOutput());
    subtract->SetInput2(g2z->GetOutput());

    // Rescale to [0, 255] unsigned char
    auto rescaler = RescaleType::New();
    rescaler->SetInput(subtract->GetOutput());
    rescaler->SetOutputMinimum(0);
    rescaler->SetOutputMaximum(255);

    auto writer = WriterType::New();
    writer->SetFileName(output);
    writer->SetInput(rescaler->GetOutput());
    writer->Update();
  }
  catch (const itk::ExceptionObject & err)
  {
    std::cerr << "ITK Exception caught:" << std::endl;
    std::cerr << err << std::endl;
    return EXIT_FAILURE;
  }
  catch (const std::exception & err)
  {
    std::cerr << "Exception caught: " << err.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
