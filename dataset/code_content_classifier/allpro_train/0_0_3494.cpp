#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (m == 3) {
        if (n < 3) {
            cout << "-1" << endl;
        } else {
            cout << "0 0" << endl;
            cout << "1 0" << endl;
            cout << "0 1" << endl;
            for (int i = 3; i < n; i++) {
                cout << i-1 << " " << i << endl;
            }
        }
    } else if (n % 2 == 0) {
        cout << "-1" << endl;
    } else {
        cout << "0 0" << endl;
        cout << "3 0" << endl;
        cout << "-3 0" << endl;
        for (int i = 1; i < (n-3)/2 + 1; i++) {
            cout << "3*" << i << " 1" << endl;
            cout << "-3*" << i << " 1" << endl;
        }
    }

    return 0;
}