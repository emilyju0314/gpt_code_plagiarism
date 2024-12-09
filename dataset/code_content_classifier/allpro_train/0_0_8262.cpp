#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int minSum = INT_MAX;
    int minIndex = 0;
    int sum = 0;

    for(int i = 0; i < k; i++) {
        sum += heights[i];
    }

    minSum = sum;
    
    for(int i = 1; i <= n - k; i++) {
        sum -= heights[i-1];
        sum += heights[i+k-1];
        
        if(sum < minSum) {
            minSum = sum;
            minIndex = i;
        }
    }

    cout << minIndex + 1 << endl;

    return 0;
}