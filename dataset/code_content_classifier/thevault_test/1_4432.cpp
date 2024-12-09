void vtkImageResliceExecute(vtkImageReslice *self,
                            vtkImageData *inData, void *inPtr,
                            vtkImageData *outData, void *outPtr,
                            int outExt[6], int id)
{
  int numscalars;
  int idX, idY, idZ;
  int idXmin, idXmax, iter;
  vtkIdType outIncX, outIncY, outIncZ;
  int scalarSize;
  int inExt[6];
  vtkIdType inInc[3];
  unsigned long count = 0;
  unsigned long target;
  double point[4];
  double f;
  double *inSpacing, *inOrigin, *outSpacing, *outOrigin, inInvSpacing[3];
  void *background;
  int (*interpolate)(void *&outPtr, const void *inPtr,
                     const int inExt[6], const vtkIdType inInc[3],
                     int numscalars, const double point[3],
                     int mode, const void *background);
  void (*setpixels)(void *&out, const void *in, int numscalars, int n);

  // the 'mode' species what to do with the 'pad' (out-of-bounds) area
  int mode = VTK_RESLICE_BACKGROUND;
  if (self->GetMirror())
    {
    mode = VTK_RESLICE_MIRROR;
    }
  else if (self->GetWrap())
    {
    mode = VTK_RESLICE_WRAP;
    }
  else if (self->GetBorder())
    {
    mode = VTK_RESLICE_BORDER;
    }

  // the transformation to apply to the data
  vtkAbstractTransform *transform = self->GetResliceTransform();
  vtkMatrix4x4 *matrix = self->GetResliceAxes();

  // for conversion to data coordinates
  inOrigin = inData->GetOrigin();
  inSpacing = inData->GetSpacing();
  outOrigin = outData->GetOrigin();
  outSpacing = outData->GetSpacing();

  // save effor later: invert inSpacing
  inInvSpacing[0] = 1.0/inSpacing[0];
  inInvSpacing[1] = 1.0/inSpacing[1];
  inInvSpacing[2] = 1.0/inSpacing[2];

  // find maximum input range
  inData->GetExtent(inExt);
  
  // for the progress meter
  target = static_cast<unsigned long>
    ((outExt[5]-outExt[4]+1)*(outExt[3]-outExt[2]+1)/50.0);
  target++;
  
  // Get Increments to march through data 
  inData->GetIncrements(inInc);
  outData->GetContinuousIncrements(outExt, outIncX, outIncY, outIncZ);
  scalarSize = outData->GetScalarSize();
  numscalars = inData->GetNumberOfScalarComponents();

  // allocate a voxel to copy into the background (out-of-bounds) regions
  vtkAllocBackgroundPixel(self, &background, numscalars);

  // get the appropriate functions for interpolation and pixel copying
  vtkGetResliceInterpFunc(self, &interpolate);
  vtkGetSetPixelsFunc(self, &setpixels);

  // get the stencil
  vtkImageStencilData *stencil = self->GetStencil();

  // Loop through output voxels
  for (idZ = outExt[4]; idZ <= outExt[5]; idZ++)
    {
    for (idY = outExt[2]; idY <= outExt[3]; idY++)
      {
      if (id == 0) 
        { // update the progress if this is the main thread
        if (!(count%target)) 
          {
          self->UpdateProgress(count/(50.0*target));
          }
        count++;
        }
      
      iter = 0; // if there is a stencil, it is applied here
      while (vtkResliceGetNextExtent(stencil, idXmin, idXmax,
                                     outExt[0], outExt[1], idY, idZ,
                                     outPtr, background, numscalars, 
                                     setpixels, iter))
        {
        for (idX = idXmin; idX <= idXmax; idX++)
          {
          // convert to data coordinates 
          point[0] = idX*outSpacing[0] + outOrigin[0];
          point[1] = idY*outSpacing[1] + outOrigin[1];
          point[2] = idZ*outSpacing[2] + outOrigin[2];

          // apply ResliceAxes matrix
          if (matrix)
            {
            point[3] = 1.0;
            matrix->MultiplyPoint(point, point);
            f = 1.0/point[3];
            point[0] *= f;
            point[1] *= f;
            point[2] *= f;
            }

          // apply ResliceTransform
          if (transform)
            {
            transform->InternalTransformPoint(point, point);
            }
          
          // convert back to voxel indices
          point[0] = (point[0] - inOrigin[0])*inInvSpacing[0];
          point[1] = (point[1] - inOrigin[1])*inInvSpacing[1];
          point[2] = (point[2] - inOrigin[2])*inInvSpacing[2];

          // interpolate output voxel from input data set
          interpolate(outPtr, inPtr, inExt, inInc, numscalars,
                      point, mode, background);
          } 
        }
      outPtr = static_cast<void *>(
        static_cast<char *>(outPtr) + outIncY*scalarSize);
      }
    outPtr = static_cast<void *>(
      static_cast<char *>(outPtr) + outIncZ*scalarSize);
    }

  vtkFreeBackgroundPixel(self, &background);
}