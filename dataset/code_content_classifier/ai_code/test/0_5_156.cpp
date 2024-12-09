#include <iostream>
#include <vector>

using namespace std;

int minSteps(vector<int>& arr, int k) {
    long long sum = 0;
    int minVal = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        minVal = min(minVal, arr[i]);
    }
    
    if (sum <= k) {
        return 0;
    }
    
    long long diff = sum - k;
    if (minVal >= diff) {
        return diff;
    }
    
    return (diff + minVal - 1) / minVal;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << minSteps(arr, k) << endl;
    }
    
    return 0;
}