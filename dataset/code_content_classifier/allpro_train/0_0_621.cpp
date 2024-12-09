#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void performOperations(vector<int>& arr, int k) {
    int max_val = *max_element(arr.begin(), arr.end());
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = max_val - arr[i];
        sum += arr[i];
    }
    
    // After one operation, the sum of the array elements will be (n - sum), where n is the number of elements
    int remaining_operations = k % 2;
    if (remaining_operations == 1) {
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = max_val - arr[i];
        }
    }
    
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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
        
        performOperations(arr, k);
    }
    
    return 0;
}