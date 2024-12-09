int Solution::canJump(vector<int> &A) {
    int curr = A[0];
    int prev = curr;
    for(int i = 1; i<A.size(); i++){
        if(curr==0)
            return 0;
        curr = max(prev-1, A[i]);
        prev = curr;
    }
    return 1;
}