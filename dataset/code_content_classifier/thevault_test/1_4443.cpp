void vtkLookupTable::ForceBuild()
{
  int i;
  double hue, sat, val, hinc, sinc, vinc, ainc;
  double rgba[4], alpha;
  unsigned char *c_rgba;

  int maxIndex = this->NumberOfColors - 1;

  if( maxIndex )
    {
    hinc = (this->HueRange[1] - this->HueRange[0])/maxIndex;
    sinc = (this->SaturationRange[1] - this->SaturationRange[0])/maxIndex;
    vinc = (this->ValueRange[1] - this->ValueRange[0])/maxIndex;
    ainc = (this->AlphaRange[1] - this->AlphaRange[0])/maxIndex;
    }
  else
    {
    hinc = sinc = vinc = ainc = 0.0; 
    }

  for (i = 0; i <= maxIndex; i++) 
    {
    hue = this->HueRange[0] + i*hinc;
    sat = this->SaturationRange[0] + i*sinc;
    val = this->ValueRange[0] + i*vinc;
    alpha = this->AlphaRange[0] + i*ainc;

    vtkMath::HSVToRGB(hue, sat, val, &rgba[0], &rgba[1], &rgba[2]);
    rgba[3] = alpha;

    c_rgba = this->Table->WritePointer(4*i,4);

    switch(this->Ramp)
      {
      case VTK_RAMP_SCURVE:
        {
        c_rgba[0] = static_cast<unsigned char> 
          (127.5*(1.0+cos((1.0-static_cast<double>(rgba[0]))*3.141593)));
        c_rgba[1] = static_cast<unsigned char> 
          (127.5*(1.0+cos((1.0-static_cast<double>(rgba[1]))*3.141593)));
        c_rgba[2] = static_cast<unsigned char> 
          (127.5*(1.0+cos((1.0-static_cast<double>(rgba[2]))*3.141593)));
        c_rgba[3] = static_cast<unsigned char> (alpha*255.0);
        /* same code, but with rounding 
           c_rgba[0] = static_cast<unsigned char> 
           (127.5f*(1.0f + (double)cos(double((1.0f-rgba[0])*3.141593f)))+0.5f);
           c_rgba[1] = static_cast<unsigned char> 
           (127.5f*(1.0f + (double)cos(double((1.0f-rgba[1])*3.141593f)))+0.5f);
           c_rgba[2] = static_cast<unsigned char> 
           (127.5f*(1.0f + (double)cos(double((1.0f-rgba[2])*3.141593f)))+0.5f);
           c_rgba[3] = static_cast<unsigned char>(rgba[3]*255.0f + 0.5f);
        */
        }
        break;
      case VTK_RAMP_LINEAR:
        {
        c_rgba[0] = static_cast<unsigned char>((rgba[0])*255.0f + 0.5f);
        c_rgba[1] = static_cast<unsigned char>((rgba[1])*255.0f + 0.5f);
        c_rgba[2] = static_cast<unsigned char>((rgba[2])*255.0f + 0.5f);
        c_rgba[3] = static_cast<unsigned char>(rgba[3]*255.0f + 0.5f);
        }
        break;
      case VTK_RAMP_SQRT:
        {
        c_rgba[0] = static_cast<unsigned char>((sqrt(rgba[0]))*255.0f + 0.5f);
        c_rgba[1] = static_cast<unsigned char>((sqrt(rgba[1]))*255.0f + 0.5f);
        c_rgba[2] = static_cast<unsigned char>((sqrt(rgba[2]))*255.0f + 0.5f);
        c_rgba[3] = static_cast<unsigned char>((sqrt(rgba[3]))*255.0f + 0.5f);
        }
        break;
      default:
        assert("check: impossible case." && 0); // reaching this line is a bug.
        break;
      }
    }
  this->BuildTime.Modified();
}