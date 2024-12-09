double vtkColorTransferFunction::GetRedValue( double x )
{
  double rgb[3];
  this->GetColor( x, rgb );

  return rgb[0];
}