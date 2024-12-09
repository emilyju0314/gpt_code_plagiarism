#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canSortArray(vector<int>& a) {
    int n = a.size();
    
    sort(a.begin(), a.end());
    
    for(int i=0; i<n; i++) {
        if(a[i] != i+1) {
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
        
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        
        if(canSortArray(a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}