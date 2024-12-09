bool won(const int d , int board[][d])
{
    int ci = 1;
    for (int r = 0 ; r < d ; r++)
    {
        for (int c = 0 ; c < d ; c++ , ci==d*d ? ci=0 : ci)
        {
            if(board[r][c]!=ci++) return 0;
        }
    }

    return 1;
}