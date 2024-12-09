#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    bool possible = true;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        if (a == x || a == 7-x || b == x || b == 7-x) {
            possible = false;
        }
    }
    
    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}