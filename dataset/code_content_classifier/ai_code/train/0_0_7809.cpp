#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << -1 << endl;
        } else {
            cout << "2";
            for (int j = 1; j < n; j++) {
                cout << "7";
            }
            cout << endl;
        }
    }

    return 0;
}