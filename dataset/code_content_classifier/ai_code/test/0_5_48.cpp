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
        
        bool possible = true;
        for(int i = 0; i < n; i++) {
            if(a[i] != i+1) {
                bool found = false;
                for(int j = i+1; j < n; j++) {
                    if(a[j] == i+1) {
                        found = true;
                        swap(a[i], a[j]);
                        break;
                    }
                }
                if(!found) {
                    possible = false;
                    break;
                }
            }
        }
        
        if(possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}