void vtkCubeAxesActor::GetBounds(double bounds[6])
{
  for (int i=0; i< 6; i++)
    {
    bounds[i] = this->Bounds[i];
    }
}