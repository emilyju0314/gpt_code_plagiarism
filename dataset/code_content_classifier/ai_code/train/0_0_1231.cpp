#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << "1" << endl;
        } else {
            cout << "1";
            for (int i = 0; i < n-2; i++) {
                cout << "3";
            }
            cout << "37" << endl;
        }
    }

    return 0;
}