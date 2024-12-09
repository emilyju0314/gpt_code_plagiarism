void vtkImageReslice::ThreadedRequestData(
  vtkInformation *vtkNotUsed(request),
  vtkInformationVector **vtkNotUsed(inputVector),
  vtkInformationVector *vtkNotUsed(outputVector),
  vtkImageData ***inData,
  vtkImageData **outData,
  int outExt[6], int id)
{

  vtkDebugMacro(<< "Execute: inData = " << inData[0][0]
                      << ", outData = " << outData[0]);

  // this filter expects that input is the same type as output.
  if (inData[0][0]->GetScalarType() != outData[0]->GetScalarType())
    {
    vtkErrorMacro(<< "Execute: input ScalarType, "
                  << inData[0][0]->GetScalarType()
                  << ", must match out ScalarType "
                  << outData[0]->GetScalarType());
    return;
    }

  int inExt[6];
  inData[0][0]->GetExtent(inExt);
  // check for empty input extent
  if (inExt[1] < inExt[0] ||
      inExt[3] < inExt[2] ||
      inExt[5] < inExt[4])
    {
    return;
    }

  // Get the output pointer
  void *outPtr = outData[0]->GetScalarPointerForExtent(outExt);

  if (this->HitInputExtent == 0)
    {
    vtkImageResliceClearExecute(this, inData[0][0], 0, outData[0], outPtr,
                                outExt, id);
    return;
    }
  
  // Now that we know that we need the input, get the input pointer
  void *inPtr = inData[0][0]->GetScalarPointerForExtent(inExt);

  if (this->Optimization)
    {
    // change transform matrix so that instead of taking 
    // input coords -> output coords it takes output indices -> input indices
    vtkMatrix4x4 *matrix = this->IndexMatrix;

    // get the portion of the transformation that remains apart from
    // the IndexMatrix
    vtkAbstractTransform *newtrans = this->OptimizedTransform;

    double newmat[4][4];
    for (int i = 0; i < 4; i++)
      {
      newmat[i][0] = matrix->GetElement(i,0);
      newmat[i][1] = matrix->GetElement(i,1);
      newmat[i][2] = matrix->GetElement(i,2);
      newmat[i][3] = matrix->GetElement(i,3);
      }
  
    if (vtkIsPermutationMatrix(newmat) && newtrans == NULL)
      {
      vtkReslicePermuteExecute(this, inData[0][0], inPtr, outData[0], outPtr,
                               outExt, id, newmat);
      }
    else
      {
      vtkOptimizedExecute(this, inData[0][0], inPtr, outData[0], outPtr,
                          outExt, id, newmat, newtrans);
      }
    }
  else
    {
    vtkImageResliceExecute(this, inData[0][0], inPtr, outData[0], outPtr,
                           outExt, id);
    }
}