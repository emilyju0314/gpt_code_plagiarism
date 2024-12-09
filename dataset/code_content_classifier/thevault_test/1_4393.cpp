void vtkCamera::Elevation(double angle)
{
  double axis[3], newPosition[3];
  double *fp = this->FocalPoint;
  this->Transform->Identity();

// snatch the axis from the view transform matrix
  axis[0] = -this->ViewTransform->GetMatrix()->GetElement(0,0);
  axis[1] = -this->ViewTransform->GetMatrix()->GetElement(0,1);
  axis[2] = -this->ViewTransform->GetMatrix()->GetElement(0,2);

// translate the focal point to the origin,
// rotate about axis,
// translate back again
  this->Transform->Translate(+fp[0],+fp[1],+fp[2]);
  this->Transform->RotateWXYZ(angle,axis);
  this->Transform->Translate(-fp[0],-fp[1],-fp[2]);

// now transform position
  this->Transform->TransformPoint(this->Position,newPosition);
  this->SetPosition(newPosition);
}