#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        if (n % 2 == 0) {
            for (int j = 0; j < n/2; j++) {
                cout << "1";
            }
        } else {
            cout << "7";
            for (int j = 0; j < (n-3)/2; j++) {
                cout << "1";
            }
        }
        cout << endl;
    }

    return 0;
}