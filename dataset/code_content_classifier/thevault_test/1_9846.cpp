int vtkGenericEnSightReader2::GetMultiProcessNumberOfProcesses()
{
    if( this->multiProcessNumberOfProcesses == -2 )
  {
  // Initialize
  if( vtkMultiProcessController::GetGlobalController() == NULL )
      this->multiProcessNumberOfProcesses = 0;
  else
      this->multiProcessNumberOfProcesses = vtkMultiProcessController::GetGlobalController()->GetNumberOfProcesses();
  }

    return this->multiProcessNumberOfProcesses;
}