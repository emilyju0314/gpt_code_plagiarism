#include <iostream>

using namespace std;

int main() {
    int a[4];
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    int sum = a[0] + a[1] + a[2] + a[3];

    if (sum % 2 != 0) {
        cout << "NO" << endl;
    } else {
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (a[i] + a[j] == sum / 2) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
        cout << "NO" << endl;
    }

    return 0;
}