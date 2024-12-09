void vtkRedistributePolyData::CopyDataArrays
(vtkDataSetAttributes* fromPd, vtkDataSetAttributes* toPd,
 vtkIdType numToCopy, vtkIdType* fromId, int myId)
{

  vtkDataArray* DataFrom;
  vtkDataArray* DataTo;
  
  int numArrays = fromPd->GetNumberOfArrays();

  for (int i=0; i<numArrays; i++)
    {
    DataFrom = fromPd->GetArray(i);
    DataTo = toPd->GetArray(i);

    this->CopyArrays (DataFrom, DataTo, numToCopy, fromId, myId);
    } 

}