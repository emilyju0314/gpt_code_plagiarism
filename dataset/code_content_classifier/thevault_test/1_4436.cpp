int vtkVPICReader::RequestData(
  vtkInformation *vtkNotUsed(reqInfo),
  vtkInformationVector **vtkNotUsed(inVector),
  vtkInformationVector *outVector)
{
  vtkInformation *outInfo = outVector->GetInformationObject(0);
  vtkImageData *output = vtkImageData::SafeDownCast(
    outInfo->Get(vtkDataObject::DATA_OBJECT()));

  // Even if the pipeline asks for a smaller subextent, give it the
  // full subextent with ghosts
  vtkStreamingDemandDrivenPipeline* pipeline =
      vtkStreamingDemandDrivenPipeline::SafeDownCast(this->GetExecutive());
  pipeline->SetUpdateExtent(outInfo, this->SubExtent);

  // Set the subextent for this processor
  output->SetExtent(this->SubExtent);

  // Ask VPICDataSet to check for additional time steps
  // If found VPICDataSet will update its structure
  this->vpicData->addNewTimeSteps();
  int numberOfTimeSteps = this->vpicData->getNumberOfTimeSteps();

  // If more time steps ParaView must update information
  if (numberOfTimeSteps > this->NumberOfTimeSteps) {

    this->NumberOfTimeSteps = numberOfTimeSteps;
    delete [] this->TimeSteps;
    this->TimeSteps = new double[this->NumberOfTimeSteps];

    for (int step = 0; step < this->NumberOfTimeSteps; step++)
      this->TimeSteps[step] = (double) this->vpicData->getTimeStep(step);

    // Tell the pipeline what steps are available
    outInfo->Set(vtkStreamingDemandDrivenPipeline::TIME_STEPS(),
                 this->TimeSteps, this->NumberOfTimeSteps);

    // Range is required to get GUI to show things
    double tRange[2];
    tRange[0] = this->TimeSteps[0];
    tRange[1] = this->TimeSteps[this->NumberOfTimeSteps - 1];
    outInfo->Set(vtkStreamingDemandDrivenPipeline::TIME_RANGE(), tRange, 2);
  }

  // Collect the time step requested
  double* requestedTimeSteps = NULL;
  int numRequestedTimeSteps = 0;
  vtkInformationDoubleVectorKey* timeKey =
    static_cast<vtkInformationDoubleVectorKey*>
      (vtkStreamingDemandDrivenPipeline::UPDATE_TIME_STEPS());

  // Actual time for the time step
  double dTime = this->TimeSteps[0];
  if (outInfo->Has(timeKey)) {
    numRequestedTimeSteps = outInfo->Length(timeKey);
    requestedTimeSteps = outInfo->Get(timeKey);
    dTime = requestedTimeSteps[0];
  }

  output->GetInformation()->Set(vtkDataObject::DATA_TIME_STEPS(), &dTime, 1);

  // Index of the time step to request
  int timeStep = 0;
  while (timeStep < this->NumberOfTimeSteps &&
         this->TimeSteps[timeStep] < dTime)
    timeStep++;

  // If this is a new time step read all the data from files
  int timeChanged = 0;
  if (this->CurrentTimeStep != timeStep) {
    timeChanged = 1;
    this->CurrentTimeStep = timeStep;
  }

  // Get size information from the VPICDataSet to set ImageData
  double origin[DIMENSION], step[DIMENSION];
  this->vpicData->getOrigin(origin);
  this->vpicData->getStep(step);
  output->SetSpacing(step);
  output->SetOrigin(origin);

  // Examine each variable to see if it is selected
  for (int var = 0; var < this->NumberOfVariables; var++) {

    // Is this variable requested
    if (this->PointDataArraySelection->GetArraySetting(var)) {
      if (this->dataLoaded[var] == 0 || timeChanged) {
        LoadVariableData(var, timeStep);
        this->dataLoaded[var] = 1;
      }
      output->GetPointData()->AddArray(this->data[var]);

    } else {
      this->dataLoaded[var] = 0;
    }
  }
  return 1;
}