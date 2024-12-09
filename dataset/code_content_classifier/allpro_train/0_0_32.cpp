#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;

    for (int i = 1; i < k; i++) {
        for (int j = 1; j < k; j++) {
            cout << i * j;
            if (j < k - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}