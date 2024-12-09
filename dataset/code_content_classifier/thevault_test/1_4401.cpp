vtkMatrix4x4 *vtkCamera::GetProjectionTransformMatrix(double aspect,
                                                      double nearz,
                                                      double farz)
{
  this->ComputeProjectionTransform(aspect, nearz, farz);

// return the transform
  return this->ProjectionTransform->GetMatrix();
}