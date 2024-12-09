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
        
        vector<int> a(2*n);
        for(int i = 0; i < 2*n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        vector<int> b(2*n);
        for(int i = 0, j = 0; i < n; i++) {
            b[j] = a[i];
            j += 2;
        }
        
        for(int i = n, j = 1; i < 2*n; i++) {
            b[j] = a[i];
            j += 2;
        }
        
        for(int i = 0; i < 2*n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}