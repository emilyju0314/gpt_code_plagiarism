Piece Piezas::pieceAt(int row, int column)
{
  //if row or column is out of bounds
  if(row >= BOARD_ROWS || column >= BOARD_COLS)
    return Invalid;

  //create temp piece and check if blank/X/O
  Piece temp = board[row][column];

  if(temp == X)
    return X;
  else if(temp == O)
    return O;
  else
    return Blank;
}