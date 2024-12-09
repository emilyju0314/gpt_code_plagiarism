#include <iostream>
#include <vector>
using namespace std;

bool isLadder(vector<int>& arr, int l, int r) {
    // Check if the subsegment from l to r is a ladder
    bool increasing = true;
    bool decreasing = true;
    for(int i = l; i < r; i++) {
        if(arr[i] > arr[i+1]) {
            increasing = false;
        } else if(arr[i] < arr[i+1]) {
            decreasing = false;
        }
    }
    return increasing || decreasing;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        if(isLadder(arr, l-1, r-1)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}