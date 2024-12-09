bool search2DMatrix(vector<vector<int>> &A, int B)
{
    //Here since the size of 2d vector is not disclosed 
    // we need to first obtain the starting and ending point of vector
   
    int N = A.size();
    int M = A[0].size();
    int start = 0, end = N * M - 1;
    //here start is  the first index and end is last index
    while (start <= end)
    {
        //Finding the mid of 2D matrix 
        int mid = start + (end - start) / 2;

        //since it is a 2D matrix we need two indices to tap in that element
        //In this way we are playing with 2D matrix as 1D
        int x = mid / M;
        int y = mid % M;

        //next is normal binary search
        if (A[x][y] == B)
            return 1;
        if (B < A[x][y])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0;
}