#include <iostream>

using namespace std;

int main() {
    int D, T, S;
    cin >> D >> T >> S;

    if (D <= T * S) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}