#include <iostream>
#include <unordered_map>
using namespace std;

int longestZeroSumSubarray(int arr[], int n) {
    unordered_map<int, int> prefixSum;
    int sum = 0, maxLength = 0;
  
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        
        if (sum == 0) {
            maxLength = i + 1;
        }
        else {
            if (prefixSum.find(sum) != prefixSum.end()) {
                maxLength = max(maxLength, i - prefixSum[sum]);
            }
            else {
                prefixSum[sum] = i;
            }
        }
    }
  
    return maxLength;
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
  
    cout << longestZeroSumSubarray(arr, n) << endl;
  
    return 0;
}