void vtkVPICReader::LoadVariableData(int var, int timeStep)
{
  this->data[var]->Delete();
  this->data[var] = vtkFloatArray::New();
  this->data[var]->SetName(VariableName[var].c_str());

  /*
  if (this->Rank == 0)
    cout << "LoadVariableData " << this->VariableName[var]
         << " time " << timeStep << endl;
  */

  // First set the number of components for this variable
  int numberOfComponents = 0;
  if (this->VariableStruct[var] == SCALAR) {
    numberOfComponents = 1;
    this->data[var]->SetNumberOfComponents(numberOfComponents);
  }
  else if (this->VariableStruct[var] == VECTOR) {
    numberOfComponents = DIMENSION;
    this->data[var]->SetNumberOfComponents(numberOfComponents);
  }
  else if (this->VariableStruct[var] == TENSOR) {
    numberOfComponents = TENSOR_DIMENSION;
    this->data[var]->SetNumberOfComponents(TENSOR9_DIMENSION);
  }

  // Second set the number of tuples which will allocate all tuples
  this->data[var]->SetNumberOfTuples(this->NumberOfTuples);

  // For each component of the requested variable load data
  float* block = new float[this->NumberOfGhostTuples];
  float* varData = this->data[var]->GetPointer(0);

  for (int comp = 0; comp < numberOfComponents; comp++) {

    // Fetch the data for a single component into temporary storage
    this->vpicData->loadVariableData(block, this->ghostLevel0,
                                     this->GhostDimension, timeStep, var, comp);

    // Exchange the single component block retrieved from files to get ghosts
#ifdef VTK_USE_MPI
    if (this->TotalRank>1)
      {
      this->exchanger->exchangeGrid(block);
      }
#endif

    // Load the ghost component block into ParaView array
    if (this->VariableStruct[var] != TENSOR) {
      LoadComponent(varData, block, comp, numberOfComponents);
    }

    else {
      // Tensors are 6 point and must be written as 9 point
      // (0->0) (1->4) (2->8) (3->5,7) (4->2,6) (5->1,3)
      switch (comp) {
      case 0:
        LoadComponent(varData, block, 0, TENSOR9_DIMENSION);
        break;
      case 1:
        LoadComponent(varData, block, 4, TENSOR9_DIMENSION);
        break;
      case 2:
        LoadComponent(varData, block, 8, TENSOR9_DIMENSION);
        break;
      case 3:
        LoadComponent(varData, block, 5, TENSOR9_DIMENSION);
        LoadComponent(varData, block, 7, TENSOR9_DIMENSION);
        break;
      case 4:
        LoadComponent(varData, block, 2, TENSOR9_DIMENSION);
        LoadComponent(varData, block, 6, TENSOR9_DIMENSION);
        break;
      case 5:
        LoadComponent(varData, block, 1, TENSOR9_DIMENSION);
        LoadComponent(varData, block, 3, TENSOR9_DIMENSION);
        break;
      }
    }
  }
  delete [] block;
}