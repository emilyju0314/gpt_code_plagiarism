Piece Piezas::gameState()
{
  //temporarily keep track of X and O totals
  int xTot = 0;
  int oTot = 0;

  //tmp track count of X/O horizontally
  int xHor = 0;
  int oHor = 0;

  //tmp track count of X/O vertically
  int xVer = 0;
  int oVer = 0;

  //if board is empty, game not over
  if(board.empty())
    return Invalid;


  //check the columns first for counts
  for(int i = 0; i < BOARD_ROWS; i++)
  {
    for(int j = 0; j < BOARD_COLS; j++)
    {
      //check if any spaces have blanks or invalids, if so game can't be over
      if( (board[i][j] == Blank)  )
        return Invalid;

      if(board[i][j] == X)
        xVer++;
      else if(board[i][j] == O)
        oVer++;

    }

    if(xTot < xVer)
      xTot = xVer;
    if(oTot < oVer)
      oTot = oVer;
  }

  for(int i = 0; i < BOARD_COLS; i++)
  {
    for(int j = 0; j < BOARD_ROWS; j++)
    {
      //No need to check for blank space here, already checked in above loop

      if(board[j][i] == X)
        xHor++;
      else if(board[j][i] == O)
        oHor++;

    }

    if(xTot < xHor)
      xTot = xHor;
    if(oTot < oHor)
      oTot = oVer;
  }

  if(xTot > oTot)
    return X;
  else if(oTot > xTot)
    return O;
  else
    return Blank;

}