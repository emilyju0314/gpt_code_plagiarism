#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int a = 0; a * 1234567 <= n; a++) {
        for (int b = 0; b * 123456 <= n; b++) {
            int remaining = n - a * 1234567 - b * 123456;
            if (remaining % 1234 == 0) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}