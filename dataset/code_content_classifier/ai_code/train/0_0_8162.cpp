#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        
        int a1, a2, a3, a4, a5;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        
        if (a1 <= c1 && a2 <= c2 && a3 <= c3) {
            if (a1 + a4 <= c1 && a2 + a5 <= c2) {
                cout << "YES\n";
            } else if (a1 + a4 <= c1 && a3 + a5 <= c3) {
                cout << "YES\n";
            } else if (a2 + a5 <= c2 && a3 + a4 <= c3) {
                cout << "YES\n";
            } else if (a1 + a4 + a3 <= c1 && a2 + a5 + a3 <= c2) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}