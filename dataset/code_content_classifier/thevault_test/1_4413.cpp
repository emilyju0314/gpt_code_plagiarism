vtkColorTransferFunction::vtkColorTransferFunction()
{
  this->UnsignedCharRGBAValue[0] = 0;
  this->UnsignedCharRGBAValue[1] = 0;
  this->UnsignedCharRGBAValue[2] = 0;
  this->UnsignedCharRGBAValue[3] = 0;
  
  this->Range[0] = 0;
  this->Range[1] = 0;

  this->Clamping = 1;
  this->ColorSpace = VTK_CTF_RGB;
  this->HSVWrap = 1; //By default HSV will be wrap

  this->Scale = VTK_CTF_LINEAR;

  this->NanColor[0] = 0.5;
  this->NanColor[1] = 0.0;
  this->NanColor[2] = 0.0;
  
  this->Function = NULL;

  this->Table = NULL;
  this->TableSize = 0;

  this->AllowDuplicateScalars = 0;

  this->Internal = new vtkColorTransferFunctionInternals;
}