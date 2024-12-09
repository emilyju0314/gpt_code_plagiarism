void draw(const int d , int board[][d])
{
    for (int r = 0 ; r < d ; r ++)
    {
        for (int c = 0 ; c < d ; c++)
        {
            if(board[r][c])
            printf("%2d ",board[r][c]);
            else
            printf("   ");
        }
        printf("\n");
    }

}