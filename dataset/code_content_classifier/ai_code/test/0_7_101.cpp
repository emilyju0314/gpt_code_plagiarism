#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool canBePermutation(int n, vector<int>& arr, string colors) {
    unordered_map<int, int> count;
    
    for(int i=0; i<n; i++) {
        if(colors[i] == 'B') {
            arr[i] *= -1;
        }
        count[arr[i]]++;
    }
    
    for(int i=1; i<=n; i++) {
        if(count[i] == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        
        string colors;
        cin >> colors;
        
        if(canBePermutation(n, arr, colors)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}