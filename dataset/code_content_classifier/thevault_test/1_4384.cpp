void vtkCamera::SetDistance(double d)
{
  if (this->Distance == d)
    {
    return;
    }

  this->Distance = d;

// Distance should be greater than .0002
  if (this->Distance < 0.0002)
    {
    this->Distance = 0.0002;
    vtkDebugMacro(<< " Distance is set to minimum.");
    }

// we want to keep the camera pointing in the same direction
  double *vec = this->DirectionOfProjection;

// recalculate FocalPoint
  this->FocalPoint[0] = this->Position[0] + vec[0]*this->Distance;
  this->FocalPoint[1] = this->Position[1] + vec[1]*this->Distance;
  this->FocalPoint[2] = this->Position[2] + vec[2]*this->Distance;

  vtkDebugMacro(<< " Distance set to ( " <<  this->Distance << ")");

  this->ComputeViewTransform();
  this->ComputeCameraLightTransform();
  this->Modified();
}