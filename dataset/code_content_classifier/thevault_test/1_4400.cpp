vtkMatrix4x4 *vtkCamera::GetPerspectiveTransformMatrix(double aspect,
                                                       double nearz,
                                                       double farz)
{
  VTK_LEGACY_REPLACED_BODY(vtkCamera::GetPerspectiveTransformMatrix,"VTK 5.4",
                           vtkCamera::GetProjectionTransformMatrix);
  return this->GetProjectionTransformMatrix(aspect,nearz,farz);
}