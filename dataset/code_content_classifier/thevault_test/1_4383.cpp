void vtkCamera::ComputeViewTransform()
{
// main view through the camera
  this->Transform->Identity();
  if (this->UserViewTransform)
    {
    this->Transform->Concatenate(this->UserViewTransform);
    }
  if ( this->HeadTracked )
    {
    this->ViewTransform->Identity();
    this->ViewTransform->SetMatrix(this->HeadTrackedViewMat);
    this->Transform->SetupCamera(this->Position,this->FocalPoint,this->ViewUp);
    this->ViewTransform->Concatenate(this->Transform->GetMatrix());
    }
  else
    {
    this->Transform->SetupCamera(this->Position,this->FocalPoint,this->ViewUp);
    this->ViewTransform->SetMatrix(this->Transform->GetMatrix());
    }
}