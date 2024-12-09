int vtkColorTransferFunction::AddRGBPoint( double x, double r,
                                           double g, double b )
{
  return this->AddRGBPoint( x, r, g, b, 0.5, 0.0 );
}