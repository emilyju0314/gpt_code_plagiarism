void vtkCamera::Zoom(double amount)
{
  if (amount <= 0.0)
    {
    return;
    }

  if (this->ParallelProjection)
    {
    this->SetParallelScale(this->ParallelScale/amount);
    }
  else
    {
    this->SetViewAngle(this->ViewAngle/amount);
    }
}