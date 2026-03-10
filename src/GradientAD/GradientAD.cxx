//
// GradientAD — Gradient Anisotropic Diffusion
// cavriley, ECE:5490 HW04
//
#include <iostream>
#include "itkCastImageFilter.h"
#include "itkGradientAnisotropicDiffusionImageFilter.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "GradientADCLP.h"

int main(int argc, char * argv[])
{
  PARSE_ARGS;

  using InputImageType = itk::Image<short, 3>;
  using RealImageType = itk::Image<float, 3>;

  using ReaderType = itk::ImageFileReader<InputImageType>;
  using CastType = itk::CastImageFilter<InputImageType, RealImageType>;
  using FilterType = itk::GradientAnisotropicDiffusionImageFilter<RealImageType, RealImageType>;
  using WriterType = itk::ImageFileWriter<RealImageType>;

  try
  {
    auto reader = ReaderType::New();
    reader->SetFileName(input);

    auto caster = CastType::New();
    caster->SetInput(reader->GetOutput());

    auto filter = FilterType::New();
    filter->SetInput(caster->GetOutput());
    filter->SetConductanceParameter(conductance);
    filter->SetTimeStep(timeStep);
    filter->SetNumberOfIterations(static_cast<unsigned int>(iterations));

    auto writer = WriterType::New();
    writer->SetFileName(output);
    writer->SetInput(filter->GetOutput());
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
