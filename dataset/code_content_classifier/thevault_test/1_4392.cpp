void vtkCamera::Azimuth(double angle)
{
  double newPosition[3];
  double *fp = this->FocalPoint;
  this->Transform->Identity();

// translate the focal point to the origin,
// rotate about view up,
// translate back again
  this->Transform->Translate(+fp[0],+fp[1],+fp[2]);
  this->Transform->RotateWXYZ(angle,this->ViewUp);
  this->Transform->Translate(-fp[0],-fp[1],-fp[2]);

// apply the transform to the position
  this->Transform->TransformPoint(this->Position,newPosition);
  this->SetPosition(newPosition);
}