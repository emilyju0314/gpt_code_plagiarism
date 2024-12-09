#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
        
        sort(a.begin(), a.end());
        
        int min_operations = 0;
        bool impossible = false;
        
        for(int i = 0; i < n; i++) {
            if(a[i] <= i+1) {
                min_operations = max(min_operations, i+1 - a[i]);
            } else {
                impossible = true;
                break;
            }
        }
        
        if(impossible) {
            cout << -1 << endl;
        } else {
            cout << min_operations << endl;
        }
    }
    
    return 0;
}