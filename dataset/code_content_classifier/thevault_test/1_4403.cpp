vtkMatrix4x4 *vtkCamera::GetCompositePerspectiveTransformMatrix(double aspect,
                                                                double nearz,
                                                                double farz)
{
  VTK_LEGACY_REPLACED_BODY(vtkCamera::GetCompositePerspectiveTransformMatrix,
                           "VTK 5.4",
                           vtkCamera::GetCompositeProjectionTransformMatrix);
  return this->GetCompositeProjectionTransformMatrix(aspect,nearz,farz);
}