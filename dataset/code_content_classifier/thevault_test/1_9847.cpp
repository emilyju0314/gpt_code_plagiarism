int vtkGenericEnSightReader2::GetMultiProcessLocalProcessId()
{
    if( this->multiProcessLocalProcessId == -2 )
  {
  // Initialize
  if( vtkMultiProcessController::GetGlobalController() == NULL )
      this->multiProcessLocalProcessId = -1;
  else
      this->multiProcessLocalProcessId = vtkMultiProcessController::GetGlobalController()->GetLocalProcessId();
  }

    return this->multiProcessLocalProcessId;
}