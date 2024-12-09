void vtkRedistributePolyData::CopyCellBlockDataArrays
(vtkDataSetAttributes* fromPd, vtkDataSetAttributes* toPd,
 vtkIdType numToCopy, vtkIdType startCell, 
 vtkIdType fromOffset, vtkIdType toOffset, int myId )
//*******************************************************************
{

  vtkDataArray* DataFrom;
  vtkDataArray* DataTo;

  int numArrays = fromPd->GetNumberOfArrays();

  for (int i=0; i<numArrays; i++)
    {
    DataFrom = fromPd->GetArray(i);
    DataTo = toPd->GetArray(i);

    this->CopyBlockArrays (DataFrom, DataTo, numToCopy, startCell, 
                           fromOffset, toOffset, myId);
    } 

}