vtkMatrix4x4 *vtkCamera::GetCameraLightTransformMatrix()
{
// return the transform
  return this->CameraLightTransform->GetMatrix();
}