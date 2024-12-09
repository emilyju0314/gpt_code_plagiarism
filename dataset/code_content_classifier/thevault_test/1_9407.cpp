Piece Piezas::dropPiece(int column)
{
  //First check if given column is out of bounds
  if(column >= BOARD_COLS)
  {
    //change turns if placed out of bounds
    if(turn == X)
      turn = O;
    else
      turn = X;
    return Invalid; 
  }

  //Switch on turns X and O
  switch(turn)
  {
    //if turn is X
    case X:
      {
        for(int i = 0; i < BOARD_ROWS; i++)
        {
          for(int j = 0; j < BOARD_COLS; j++)
          {
            //check to see we have right column, and is not already taken up by X or O
            if( (j == column) && (board[i][j] != X) && (board[i][j] != O) )
            {
              board[i][j] = X;
              turn = O;
              return X;
            }
          }
        }//for
        break;
      }
    //if turn is O
    case O:
      {
        for(int i = 0; i < BOARD_ROWS; i++)
        {
          for(int j = 0; j < BOARD_COLS; j++)
          {
            if( j == column && (board[i][j] != X) && (board[i][j] != O) )
            {
              board[i][j] = O;
              turn = X;
              return O;
            }
          }
        }//for
        break;
      }
  }//switch
    return Blank;
}