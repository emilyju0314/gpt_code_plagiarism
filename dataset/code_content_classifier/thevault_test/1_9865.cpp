void vtkPVGeometryFilter::ExecuteCellNormals(vtkPolyData* output, int doCommunicate)
{
  if ( ! this->GenerateCellNormals)
    {
    return;
    }

  // Do not generate cell normals if any of the processes
  // have lines, verts or strips.
  vtkCellArray* aPrim;
  int skip = 0;
  aPrim = output->GetVerts();
  if (aPrim && aPrim->GetNumberOfCells())
    {
    skip = 1;
    }
  aPrim = output->GetLines();
  if (aPrim && aPrim->GetNumberOfCells())
    {
    skip = 1;
    }
  aPrim = output->GetStrips();
  if (aPrim && aPrim->GetNumberOfCells())
    {
    skip = 1;
    }
  if( this->Controller && doCommunicate )
    {
    int reduced_skip = 0;
    if (!this->Controller->AllReduce(&skip, &reduced_skip, 1,
        vtkCommunicator::MAX_OP))
      {
      vtkErrorMacro("Failed to reduce correctly.");
      skip = 1;
      }
    else
      {
      skip = reduced_skip;
      }
    }
  if (skip)
    {
    return;
    }

  vtkIdType* endCellPtr;
  vtkIdType* cellPtr;
  vtkIdType *pts = 0;
  vtkIdType npts = 0;
  double polyNorm[3];
  vtkFloatArray* cellNormals = vtkFloatArray::New();
  cellNormals->SetName("cellNormals");
  cellNormals->SetNumberOfComponents(3);
  cellNormals->Allocate(3*output->GetNumberOfCells());

  aPrim = output->GetPolys();
  if (aPrim && aPrim->GetNumberOfCells())
    {
    vtkPoints* p = output->GetPoints();

    cellPtr = aPrim->GetPointer();
    endCellPtr = cellPtr+aPrim->GetNumberOfConnectivityEntries();

    while (cellPtr < endCellPtr)
      {
      npts = *cellPtr++;
      pts = cellPtr;
      cellPtr += npts;

      vtkPolygon::ComputeNormal(p,npts,pts,polyNorm);
      cellNormals->InsertNextTuple(polyNorm);    
      }
    }

  if (cellNormals->GetNumberOfTuples() != output->GetNumberOfCells())
    {
    vtkErrorMacro("Number of cell normals does not match output.");
    cellNormals->Delete();
    return;
    }

  output->GetCellData()->AddArray(cellNormals);
  output->GetCellData()->SetActiveNormals(cellNormals->GetName());
  cellNormals->Delete();
  cellNormals = NULL;
}