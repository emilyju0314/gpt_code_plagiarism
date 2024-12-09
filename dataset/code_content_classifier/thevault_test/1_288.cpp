int *constructBITree(int arr[], int n){
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;/// Create and initialize BITree[] as 0
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);/// Store the actual values in BITree[] using update()

    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //      cout << BITree[i] << " ";

    return BITree;
}