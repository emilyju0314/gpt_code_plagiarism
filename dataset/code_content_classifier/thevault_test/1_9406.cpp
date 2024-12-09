void Piezas::reset()
{
  for(int i = 0; i < BOARD_ROWS; i++)
  {
    for(int j = 0; j < BOARD_COLS; j++)
      board[i][j] = Blank;
  }
}