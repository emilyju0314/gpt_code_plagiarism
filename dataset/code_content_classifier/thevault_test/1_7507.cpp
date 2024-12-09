Matrix Matrix::cofactor(float a[100][100],int rw,int cl,int N)
{
    int i = 0, j = 0;
    Matrix temp(c,r);

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != rw && col != cl)
            {
                temp.m[i][j++] = a[row][col];


                if (j == N - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return temp;
}