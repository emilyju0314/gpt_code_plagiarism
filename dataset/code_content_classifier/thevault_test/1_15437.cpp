int maxSubSum(int arr[]){
    int currSum=0;
    int maxSum=0;
    for(int i=0;i<5;i++){
        currSum+=arr[i];
        if(currSum>maxSum){
            maxSum=currSum;
        }
        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
}