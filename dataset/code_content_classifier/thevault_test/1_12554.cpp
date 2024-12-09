void CloneUnstructuredGrid(vtkUnstructuredGrid* ug, vtkUnstructuredGrid* clone,
    UnstructuredGridInformation& info)
{
  CloneDataObject(ug, clone);
  ClonePointData(ug, clone, info);
  ClonePoints(ug, clone, info);
  CloneCellData(ug, clone, info);

  if (vtkIdList* redirectionMap = info.OutputToInputCellIdRedirectionMap)
  {
    DeepCopyCells(ug->GetCells(), clone->GetCells(), redirectionMap,
        info.InputToOutputPointIdRedirectionMap);
    ug->GetCellTypesArray()->GetTuples(redirectionMap, clone->GetCellTypesArray());

    vtkIdTypeArray* ugFaceLocations = ug->GetFaceLocations();
    if (clone->GetFaceLocations() && ugFaceLocations && ugFaceLocations->GetNumberOfValues())
    {
      DeepCopyPolyhedrons(ug, clone, info);
    }
  }
  else
  {
    vtkCellArray* ugCellArray = ug->GetCells();
    vtkCellArray* cloneCellArray = clone->GetCells();
    vtkDataArray* ugConnectivity = ugCellArray->GetConnectivityArray();
    vtkDataArray* ugOffsets = ugCellArray->GetOffsetsArray();

    ugConnectivity->GetTuples(0, ugConnectivity->GetNumberOfTuples() - 1,
        cloneCellArray->GetConnectivityArray());
    ugOffsets->GetTuples(0, ugOffsets->GetNumberOfTuples() - 1, cloneCellArray->GetOffsetsArray());
    ug->GetCellTypesArray()->GetTuples(0, ug->GetNumberOfCells() - 1, clone->GetCellTypesArray());

    vtkIdTypeArray* ugFaces = ug->GetFaces();
    if (clone->GetFaces() && ugFaces && ugFaces->GetNumberOfValues())
    {
      ug->GetFaceLocations()->GetTuples(0, ug->GetNumberOfCells() - 1, clone->GetFaceLocations());
      ug->GetFaces()->GetTuples(0, ug->GetFaces()->GetNumberOfValues() - 1, clone->GetFaces());
    }
  }
}