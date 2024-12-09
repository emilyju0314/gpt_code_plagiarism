bool TicTacToeBoard::isMovesLeft()
{
    for (int row = 0; row < mRowCount; row++)
    {
        for (int col = 0; col < mColCount; col++)
        {
            if (mGameField[row][col] == eFIELD_MOVES::eFM_EMPTY)
            {
                return true;
            }
        }
    }
    
    return false;
}