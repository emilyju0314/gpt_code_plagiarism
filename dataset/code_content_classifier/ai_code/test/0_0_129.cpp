#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minOperationsToPermutation(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int operations = 0;
    
    for (int i = 1; i <= n; i++) {
        if (arr[i-1] >= i) {
            operations = max(operations, arr[i-1] / i);
        }
    }
    
    return n - operations;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        int result = minOperationsToPermutation(arr);
        cout << (result >= 0 ? result : -1) << endl;
    }
    
    return 0;
}