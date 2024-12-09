void vtkColorTransferFunction::AddHSVSegment( double x1, double h1, 
                                              double s1, double v1, 
                                              double x2, double h2, 
                                              double s2, double v2 )
{
  double r1, r2, b1, b2, g1, g2;
  
  vtkMath::HSVToRGB(h1, s1, v1, &r1, &g1, &b1);
  vtkMath::HSVToRGB(h2, s2, v2, &r2, &g2, &b2);
  this->AddRGBSegment( x1, r1, g1, b1, x2, r2, g2, b2 );
}