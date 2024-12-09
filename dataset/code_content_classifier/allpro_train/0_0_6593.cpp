#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int min_operations(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> first, last;
    
    for(int i=0; i<n; i++) {
        if(first.find(arr[i]) == first.end()) {
            first[arr[i]] = i;
        }
        last[arr[i]] = i;
    }
    
    int max_range = 0;
    int ops = 0;
    
    for(int i=0; i<n; i++) {
        if(i == first[arr[i]]) {
            max_range = max(max_range, last[arr[i]]);
        }
        if(i == max_range) {
            ops++;
        }
    }
    
    return n - ops;
}

int main() {
    int q;
    cin >> q;
    
    while(q--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        
        cout << min_operations(arr) << endl;
    }
    
    return 0;
}