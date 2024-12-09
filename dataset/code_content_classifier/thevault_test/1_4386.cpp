void vtkCamera::Dolly(double amount)
{
  if (amount <= 0.0)
    {
    return;
    }

// dolly moves the camera towards the focus
  double d = this->Distance/amount;

  this->SetPosition(this->FocalPoint[0] - d*this->DirectionOfProjection[0],
                    this->FocalPoint[1] - d*this->DirectionOfProjection[1],
                    this->FocalPoint[2] - d*this->DirectionOfProjection[2]);
}