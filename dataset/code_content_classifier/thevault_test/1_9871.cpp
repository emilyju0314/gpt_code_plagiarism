int vtkSMUtilities::SaveImageOnProcessZero(vtkImageData* image,
                   const char* filename, const char* writerName)
{
  int error_code;
  vtkMultiProcessController *controller =
    vtkMultiProcessController::GetGlobalController();

  if (controller)
    {
    if (controller->GetLocalProcessId() == 0)
      {
      error_code = SaveImage(image, filename, writerName);
      }
    controller->Broadcast(&error_code, 1, 0);
    }
  else
    {
    error_code = SaveImage(image, filename, writerName);
    }

  return error_code;
}