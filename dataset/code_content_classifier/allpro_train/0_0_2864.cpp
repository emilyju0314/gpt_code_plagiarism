#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    vector<int> boardSizes(T);
    for (int i = 0; i < T; i++) {
        cin >> boardSizes[i];
    }

    for (int i = 0; i < T; i++) {
        int size = boardSizes[i];
        if (size % 2 == 0) {
            cout << 1 << endl; // Gena wins
        } else {
            cout << 0 << endl; // Petya wins
        }
    }

    return 0;
}