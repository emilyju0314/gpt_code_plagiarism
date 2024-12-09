#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long a, b;
        cin >> a >> b;

        if (a == 0 || b == 0) {
            cout << "Second" << endl;
        } else if (a == 1) {
            cout << ((b % 2 == 0) ? "Second" : "First") << endl;
        } else {
            cout << "First" << endl;
        }
    }

    return 0;
}