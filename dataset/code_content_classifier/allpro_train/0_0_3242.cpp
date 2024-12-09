#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    char arr[n][m];

    bool right = true;
    int count = 1;

    for (int i = 0; i < n; i++) {
        if (right) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = '#';
            }
            right = false;
        } else {
            if (count % 2 != 0) {
                arr[i][0] = '#';
                for (int j = 1; j < m; j++) {
                    arr[i][j] = '.';
                }
            } else {
                for (int j = 0; j < m - 1; j++) {
                    arr[i][j] = '.';
                }
                arr[i][m - 1] = '#';
            }
            right = true;
            count++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}