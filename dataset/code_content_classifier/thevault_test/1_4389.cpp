void vtkCamera::Roll(double angle)
{
  double newViewUp[3];
  this->Transform->Identity();

// rotate ViewUp about the Direction of Projection
  this->Transform->RotateWXYZ(angle,this->DirectionOfProjection);

// okay, okay, TransformPoint shouldn't be used on vectors -- but
// the transform is rotation with no translation so this works fine.
  this->Transform->TransformPoint(this->ViewUp,newViewUp);
  this->SetViewUp(newViewUp);
}