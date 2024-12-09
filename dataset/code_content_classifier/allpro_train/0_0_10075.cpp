#include <iostream>

using namespace std;

int main() {
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;

    for (int i = 0; i <= t; i++) {
        if (a-da*i == x || b-db*i == x || a-da*i + b-db*i == x) {
            cout << "YES" << endl;
            return 0;
        }
    }

    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= t; j++) {
            if (a-da*i + b-db*j == x || a-da*i == x || b-db*j == x) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}