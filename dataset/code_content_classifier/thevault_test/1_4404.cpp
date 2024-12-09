vtkMatrix4x4 *vtkCamera::GetCompositeProjectionTransformMatrix(double aspect,
                                                               double nearz,
                                                               double farz)
{
// turn off stereo, the CompositeProjectionTransformMatrix is used for
// picking, not for rendering.
  int stereo = this->Stereo;
  this->Stereo = 0;

  this->Transform->Identity();
  this->Transform->Concatenate(this->GetProjectionTransformMatrix(aspect,
                                                                  nearz,
                                                                  farz));
  this->Transform->Concatenate(this->GetViewTransformMatrix());

  this->Stereo = stereo;

// return the transform
  return this->Transform->GetMatrix();
}