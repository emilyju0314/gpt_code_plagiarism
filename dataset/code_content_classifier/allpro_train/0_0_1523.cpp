#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        if(i % 2 == 1) {
            // Left non-window seat
            if(i % 4 == 1) {
                cout << n + i/2 + 1 << " ";
            }
            // Left window seat
            else {
                cout << (i + 1) / 2 << " ";
            }
        } else {
            // Right non-window seat
            if(i % 4 == 2) {
                cout << n + i/2 + 1 << " ";
            }
            // Right window seat
            else {
                cout << (i + 1) / 2 << " ";
            }
        }
    }

    return 0;
}