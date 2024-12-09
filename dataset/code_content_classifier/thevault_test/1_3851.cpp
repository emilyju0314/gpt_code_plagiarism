int Solution::maxSubArray(const vector<int> &A) {
    int currmax = A[0];
    int maxsofar = A[0];
    for(int i = 1; i<A.size(); i++) {
        currmax = max(A[i], currmax + A[i]);
        maxsofar = max(maxsofar, currmax);
    }
    return maxsofar;
}