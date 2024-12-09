#include <bits/stdc++.h>
using namespace std;

bool is_beautiful(vector<int> a, int d) {
    for(int i = 0; i < a.size() - 1; i++) {
        if((a[i] % d == 0 && a[i+1] % d == 0) || (a[i] % d != 0 && a[i+1] % d != 0)) {
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
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        bool found = false;
        for(int i = 1; i <= a[0]; i++) {
            if(is_beautiful(a, i)) {
                cout << i << endl;
                found = true;
                break;
            }
        }
        
        if(!found) {
            cout << 0 << endl;
        }
    }
    
    return 0;
}