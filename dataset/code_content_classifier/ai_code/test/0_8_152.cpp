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
        
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }
        
        vector<int> a(n);
        bool possible = true;
        
        for(int i = 0; i < n; i++) {
            if(i > 0 && p[i] < p[i-1]) {
                a[i] = -p[i];
            } else {
                a[i] = p[i];
            }
        }
        
        for(int i = 1; i < n; i++) {
            if(abs(a[i]) < abs(a[i-1])) {
                possible = false;
                break;
            }
        }
        
        if(possible) {
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}