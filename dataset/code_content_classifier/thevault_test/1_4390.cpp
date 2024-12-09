void vtkCamera::Yaw(double angle)
{
  double newFocalPoint[3];
  double *pos = this->Position;
  this->Transform->Identity();

// translate the camera to the origin,
// rotate about axis,
// translate back again
  this->Transform->Translate(+pos[0],+pos[1],+pos[2]);
  this->Transform->RotateWXYZ(angle,this->ViewUp);
  this->Transform->Translate(-pos[0],-pos[1],-pos[2]);

// now transform focal point
  this->Transform->TransformPoint(this->FocalPoint,newFocalPoint);
  this->SetFocalPoint(newFocalPoint);
}