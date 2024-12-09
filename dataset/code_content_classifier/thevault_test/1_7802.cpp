void EditDistance::PutAt (int *pOrigin, int col, int row, int nCols, int x)
{
int *pCell;

  pCell = GetCellPointer (pOrigin, col, row, nCols);
  *pCell = x;

}