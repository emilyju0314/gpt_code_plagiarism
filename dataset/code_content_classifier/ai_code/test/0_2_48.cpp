#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canSortArray(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] != i+1) {
            count++;
        }
    }
    
    return count <= 2;
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
        
        if (canSortArray(arr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}