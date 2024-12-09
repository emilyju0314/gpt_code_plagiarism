#include <iostream>

using namespace std;

int main() {
    int D, L;
    cin >> D >> L;

    int jumps = 0;
    while (D > 0) {
        if (D >= L) {
            D -= L;
            jumps++;
        } else {
            D--;
            jumps++;
        }
    }

    cout << jumps << endl;

    return 0;
}