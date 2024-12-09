int Solution::minPathSum(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    //Initialising the count vector with INT_MAX as
    //this is a minimisation operation.
    vector<vector<int> > count(r, vector<int>(c, pow(2,32) - 1));
    //Since we start bottom up, the bottom right element
    //is our starting point
    count[r-1][c-1] = A[r-1][c-1];
    for(int i = r-1; i>=0; i--) {
        for(int j = c-1; j>=0; j--) {
            //if an element to the top exists, populate it's
            //value if we found a better min cost path to it.
            //Initial value is INT_MAX so the value will be
            //updated at least once
            if(i-1>=0)
                count[i-1][j] = min(count[i-1][j], count[i][j] + A[i-1][j]);
            //Doing the same if an element to the left exists
            if(j-1>=0)
                count[i][j-1] = min(count[i][j-1], count[i][j] + A[i][j-1]);
        }
    }
    //The answer as a result would have accumulated to the
    //top left node
    return count[0][0];
}