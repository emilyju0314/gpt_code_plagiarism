vtkCamera *vtkCamera::New()
{
// First try to create the object from the vtkObjectFactory
  vtkObject* ret = vtkGraphicsFactory::CreateInstance("vtkCamera");
  return static_cast<vtkCamera *>(ret);
}