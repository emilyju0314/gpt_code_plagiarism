double vtkColorTransferFunction::GetBlueValue( double x )
{
  double rgb[3];
  this->GetColor( x, rgb );

  return rgb[2];
}