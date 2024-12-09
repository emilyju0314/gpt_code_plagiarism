#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;

    if (k == 1) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if ((i + j) % 2 == 0) {
                    cout << "b";
                } else {
                    cout << "w";
                }
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if ((i + j) % 2 == 0) {
                    cout << "w";
                } else {
                    cout << "b";
                }
            }
            cout << endl;
        }
    }

    return 0;
}