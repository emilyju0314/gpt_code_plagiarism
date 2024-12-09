int EditDistance::GetAt (int *pOrigin, int col, int row, int nCols)
{
int *pCell;

  pCell = GetCellPointer (pOrigin, col, row, nCols);
  return *pCell;

}