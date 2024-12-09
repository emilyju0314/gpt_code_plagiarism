#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        if (m < n-1 || n*(n-1)/2 < m || k <= 2) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    
    return 0;
}