#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canSort(vector<int> a, vector<int> positions) {
    for(int i=0; i<positions.size(); i++) {
        if(a[positions[i]-1] > a[positions[i]]) {
            swap(a[positions[i]-1], a[positions[i]]);
        }
    }
    
    for(int i=1; i<a.size(); i++) {
        if(a[i] < a[i-1]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        
        vector<int> positions(m);
        for(int i=0; i<m; i++) {
            cin >> positions[i];
        }
        
        if(canSort(a, positions)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}