vtkIsoVolume::vtkIsoVolume()
{
  this->LowerThreshold         = 0.0;
  this->UpperThreshold         = 1.0;
  this->UsingPointScalars      = false;

  this->LowerBoundClipDS = 0;
  this->UpperBoundClipDS = 0;
  this->Threshold        = 0;

  this->SetInputArrayToProcess(
    0,0,0,vtkDataObject::FIELD_ASSOCIATION_POINTS,
    vtkDataSetAttributes::SCALARS);
  this->SetNumberOfInputPorts(1);
}