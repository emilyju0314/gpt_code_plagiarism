void vtkCamera::Pitch(double angle)
{
  double axis[3], newFocalPoint[3];
  double *pos = this->Position;
  this->Transform->Identity();

// the axis is the first row of the view transform matrix
  axis[0] = this->ViewTransform->GetMatrix()->GetElement(0,0);
  axis[1] = this->ViewTransform->GetMatrix()->GetElement(0,1);
  axis[2] = this->ViewTransform->GetMatrix()->GetElement(0,2);

// translate the camera to the origin,
// rotate about axis,
// translate back again
  this->Transform->Translate(+pos[0],+pos[1],+pos[2]);
  this->Transform->RotateWXYZ(angle,axis);
  this->Transform->Translate(-pos[0],-pos[1],-pos[2]);

// now transform focal point
  this->Transform->TransformPoint(this->FocalPoint,newFocalPoint);
  this->SetFocalPoint(newFocalPoint);
}