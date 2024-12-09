void vtkCamera::ComputePerspectiveTransform(double aspect,
                                            double nearz, double farz)
{
  VTK_LEGACY_REPLACED_BODY(vtkCamera::ComputePerspectiveTransform,"VTK 5.4",vtkCamera::ComputeProjectionTransform);
  this->ComputeProjectionTransform(aspect,nearz,farz);
}