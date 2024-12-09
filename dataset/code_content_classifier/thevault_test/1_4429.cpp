void vtkGetSetPixelsFunc(vtkImageReslice *self,
                         void (**setpixels)(void *&out, const void *in,
                                            int numscalars, int n))
{
  int dataType = self->GetOutput()->GetScalarType();
  int numscalars = self->GetOutput()->GetNumberOfScalarComponents();

  switch (numscalars)
    {
    case 1:
      switch (dataType)
        {
        vtkTemplateAliasMacro(
          *setpixels = &vtkImageResliceSetPixels<VTK_TT>::Set1
          );
        default:
          *setpixels = 0;
        }
    default:
      switch (dataType)
        {
        vtkTemplateAliasMacro(
          *setpixels = &vtkImageResliceSetPixels<VTK_TT>::Set
          );
        default:
          *setpixels = 0;
        }
    }
}