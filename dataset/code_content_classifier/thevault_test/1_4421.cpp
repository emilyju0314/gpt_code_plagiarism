unsigned char *vtkColorTransferFunction::MapValue( double x )
{
  double rgb[3];
  this->GetColor( x, rgb );
  
  this->UnsignedCharRGBAValue[0] =
    static_cast<unsigned char>(255.0*rgb[0] + 0.5);
  this->UnsignedCharRGBAValue[1] =
    static_cast<unsigned char>(255.0*rgb[1] + 0.5);
  this->UnsignedCharRGBAValue[2] =
    static_cast<unsigned char>(255.0*rgb[2] + 0.5);
  this->UnsignedCharRGBAValue[3] = 255;
  return this->UnsignedCharRGBAValue;
}