int vtkColorTransferFunction::AddHSVPoint( double x, double h,
                                           double s, double v,
                                           double midpoint,
                                           double sharpness )
{ 
  double r, b, g;
  
  vtkMath::HSVToRGB(h, s, v, &r, &g, &b);
  return this->AddRGBPoint( x, r, g, b, midpoint, sharpness );
}