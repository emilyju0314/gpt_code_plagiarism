#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canBeMerged(vector<int>& p, int n) {
    vector<int> a, b;
    
    for (int i = 0; i < 2*n; i++) {
        if (a.empty() || p[i] < a[0]) {
            a.insert(a.begin(), p[i]);
        } else {
            b.insert(b.begin(), p[i]);
        }
    }
    
    if(a.size() != n || b.size() != n) {
        return false;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1] || b[i] < b[i-1]) {
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
        
        vector<int> p(2*n);
        for (int i = 0; i < 2*n; i++) {
            cin >> p[i];
        }
        
        if (canBeMerged(p, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}