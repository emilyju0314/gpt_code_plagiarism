#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    bool possible = false;

    for (int i = 0; i <= N / 4; i++) {
        if ((N - 4 * i) % 7 == 0) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}