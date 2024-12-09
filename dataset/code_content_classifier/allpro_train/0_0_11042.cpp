#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;

    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < (1 << k); j++) {
            if ((i & j) == 0) {
                cout << "+";
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}