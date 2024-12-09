void init(const int d , int board[][d])
{
    int inject = d*d-1;
    for(int r = 0 ; r < d ; r++)
    {
        for(int c = 0 ; c < d ; c++)
        {
            board[r][c]=inject;
            inject--;
        }
    }

    if(d%2==0) swap(&board[d-1][d-2], &board[d-1][d-3]);

}