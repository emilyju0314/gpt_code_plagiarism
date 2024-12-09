void vtkColorTransferFunctionMapData(vtkColorTransferFunction* self,
                                     unsigned short* input,
                                     unsigned char* output,
                                     int length, int inIncr,
                                     int outFormat, int)
{
  int            x;
  int            i = length;
  unsigned char  *optr = output;
  unsigned short *iptr = input;

  if(self->GetSize() == 0)
    {
    vtkGenericWarningMacro("Transfer Function Has No Points!");
    return;
    }
  

  const unsigned char *table = self->GetTable(0,65535,65536);
  switch (outFormat)
    {
    case VTK_RGB:
      while (--i >= 0) 
        {
        x = *iptr*3;
        *(optr++) = table[x];
        *(optr++) = table[x+1];
        *(optr++) = table[x+2];
        iptr += inIncr;
        }
      break;
    case VTK_RGBA:
      while (--i >= 0) 
        {
        x = *iptr*3;
        *(optr++) = table[x];
        *(optr++) = table[x+1];
        *(optr++) = table[x+2];
        *(optr++) = 255;
        iptr += inIncr;
        }
      break;
    case VTK_LUMINANCE_ALPHA:
      while (--i >= 0) 
        {
        x = *iptr*3;
        *(optr++) = table[x];
        *(optr++) = 255;
        iptr += inIncr;
        }
      break;
    case VTK_LUMINANCE:
      while (--i >= 0) 
        {
        x = *iptr*3;
        *(optr++) = table[x];
        iptr += inIncr;
        }
      break;
    }  
}