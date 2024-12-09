#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int numBigTables = n % m;
        int numSmallTables = m - numBigTables;
        int bigTableSize = n / m + 1;
        int smallTableSize = n / m;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) {
                if (j < numBigTables) {
                    cout << bigTableSize;
                    for (int p = 0; p < bigTableSize; p++) {
                        cout << " " << m*p + j + 1;
                    }
                    cout << endl;
                } else {
                    cout << smallTableSize;
                    for (int p = 0; p < smallTableSize; p++) {
                        cout << " " << m*p + j + 1;
                    }
                    cout << endl;
                }
            }
        }
        cout << endl;
    }

    return 0;
}