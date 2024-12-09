void vtkGaussianScalarSplatter::ComputeModelBounds(vtkDataSet *input,
                                             vtkImageData *output,
                                             vtkInformation *outInfo)
{
  double *bounds;
  double maxDist;
  int i;

  maxDist = this->StandardDeviation * NUMBER_OF_STD_DEVIATIONS;
  bounds = input->GetBounds();
  for (i = 0; i < 3; i ++)
    {
    if ( this->SampleDimensions[i] > 1 )
      {
      this->ModelBounds[2*i  ] = bounds[2*i  ] - maxDist;
      this->ModelBounds[2*i+1] = bounds[2*i+1] + maxDist;
      }
    else
      {
      this->ModelBounds[2*i  ] = bounds[2*i  ];
      this->ModelBounds[2*i+1] = bounds[2*i+1];
      }
    }

  // Set volume origin and data spacing
  outInfo->Set(vtkDataObject::ORIGIN(),
               this->ModelBounds[0],
               this->ModelBounds[2],
               this->ModelBounds[4]);
  memcpy(this->Origin,outInfo->Get(vtkDataObject::ORIGIN()), sizeof(double)*3);
  output->SetOrigin(this->Origin);

  for (i=0; i<3; i++)
    {
    if ( this->SampleDimensions[i] > 1 )
      {
      this->Spacing[i] = (this->ModelBounds[2*i+1] - this->ModelBounds[2*i])
        / (this->SampleDimensions[i] - 1);
      }
    else
      {
      this->Spacing[i] = 1.0;
      }
    if ( this->Spacing[i] <= 0.0 )
      {
      this->Spacing[i] = 1.0;
      }
    }
  outInfo->Set(vtkDataObject::SPACING(),this->Spacing,3);
  output->SetSpacing(this->Spacing);
}