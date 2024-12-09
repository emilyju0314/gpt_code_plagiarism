#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int maxBlocks = 1;
    int currentBlock = 1;
    for(int i = 1; i < n; i++) {
        if(heights[i] >= heights[i-1]) {
            currentBlock++;
        } else {
            maxBlocks = max(maxBlocks, currentBlock);
            currentBlock = 1;
        }
    }
    maxBlocks = max(maxBlocks, currentBlock);

    cout << maxBlocks << endl;

    return 0;
}