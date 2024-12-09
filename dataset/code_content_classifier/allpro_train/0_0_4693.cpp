#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0) {
                    cout << "B";
                } else {
                    cout << "W";
                }
            }
            cout << endl;
        }
    }

    return 0;
}  