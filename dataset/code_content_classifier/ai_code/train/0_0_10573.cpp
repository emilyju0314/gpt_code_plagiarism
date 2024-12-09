#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    
    if (a % 2 == 0) {
        cout << 6;
        for (int i = 0; i < a / 2 - 1; i++) {
            cout << 0;
        }
    } else if (a % 5 == 0) {
        cout << 6;
        for (int i = 0; i < a - 1; i++) {
            cout << 6;
        }
    } else {
        cout << -1;
    }

    return 0;
}