#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    cout << "0 ";
                } else {
                    if ((i + j) % 2 == 0) {
                        cout << "1 ";
                    } else {
                        cout << "-1 ";
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}