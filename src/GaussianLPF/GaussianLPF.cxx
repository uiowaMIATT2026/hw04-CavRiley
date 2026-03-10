//
// GaussianLPF — Gaussian Low-Pass Filter
// cavriley, ECE:5490 HW04
//
#include <iostream>
#include "itkCastImageFilter.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkRecursiveGaussianImageFilter.h"
#include "GaussianLPFCLP.h"

int main(int argc, char * argv[])
{
  PARSE_ARGS;

  using InputImageType = itk::Image<short, 3>;
  using RealImageType = itk::Image<float, 3>;

  using ReaderType = itk::ImageFileReader<InputImageType>;
  using CastType = itk::CastImageFilter<InputImageType, RealImageType>;
  using GaussianType = itk::RecursiveGaussianImageFilter<RealImageType, RealImageType>;
  using WriterType = itk::ImageFileWriter<RealImageType>;

  try
  {
    auto reader = ReaderType::New();
    reader->SetFileName(input);

    auto caster = CastType::New();
    caster->SetInput(reader->GetOutput());

    // Apply Gaussian in X direction
    auto gaussianX = GaussianType::New();
    gaussianX->SetInput(caster->GetOutput());
    gaussianX->SetSigma(sigma);
    gaussianX->SetDirection(0);
    gaussianX->SetNormalizeAcrossScale(false);

    // Apply Gaussian in Y direction
    auto gaussianY = GaussianType::New();
    gaussianY->SetInput(gaussianX->GetOutput());
    gaussianY->SetSigma(sigma);
    gaussianY->SetDirection(1);
    gaussianY->SetNormalizeAcrossScale(false);

    // Apply Gaussian in Z direction
    auto gaussianZ = GaussianType::New();
    gaussianZ->SetInput(gaussianY->GetOutput());
    gaussianZ->SetSigma(sigma);
    gaussianZ->SetDirection(2);
    gaussianZ->SetNormalizeAcrossScale(false);

    auto writer = WriterType::New();
    writer->SetFileName(output);
    writer->SetInput(gaussianZ->GetOutput());
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
