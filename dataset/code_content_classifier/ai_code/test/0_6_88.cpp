#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossibleToSplit(vector<int>& a) {
    int n = a.size();
    if (n <= 2) {
        return false;
    }
    
    int mx = a[0];
    int cnt = 0;
    
    for (int i = 1; i < n; i++) {
        if (a[i] < mx) {
            cnt++;
        }
        mx = max(mx, a[i]);
    }
    
    return cnt >= 2;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (isPossibleToSplit(a)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}