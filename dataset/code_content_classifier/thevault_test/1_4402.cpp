vtkPerspectiveTransform *vtkCamera::GetProjectionTransformObject(double aspect,
                                                                 double nearz,
                                                                 double farz)
{
  this->ComputeProjectionTransform(aspect, nearz, farz);

// return the transform
  return this->ProjectionTransform;
}