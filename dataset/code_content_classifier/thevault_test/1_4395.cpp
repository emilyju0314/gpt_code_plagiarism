void vtkCamera::SetThickness(double s)
{
  if (this->Thickness == s)
    {
    return;
    }

  this->Thickness = s;

// thickness should be greater than 1e-20
  if (this->Thickness < 1e-20)
    {
    this->Thickness = 1e-20;
    vtkDebugMacro(<< " ClippingRange thickness is set to minimum.");
    }

// set back plane
  this->ClippingRange[1] = this->ClippingRange[0] + this->Thickness;

  vtkDebugMacro(<< " ClippingRange set to ( " <<  this->ClippingRange[0]
                << ", " << this->ClippingRange[1] << ")");

  this->Modified();
}