#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    bool found = false;
    
    for (int l = 1; l <= a + b; l++) {
        int r = a + b - l;
        if (l % 2 == 0 && r % 2 == 0 && l <= a && r <= b) {
            found = true;
            break;
        }
    }
    
    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}