#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int l1, l2, l3;
        cin >> l1 >> l2 >> l3;
        
        if (l1 + l2 == l3 || l1 + l3 == l2 || l2 + l3 == l1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}