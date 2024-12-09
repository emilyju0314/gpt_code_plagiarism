vtkActor *vtkActor::New()
{
  // First try to create the object from the vtkGraphicsFactory
  vtkObject* ret = vtkGraphicsFactory::CreateInstance("vtkActor");
  return static_cast<vtkActor *>(ret);
}