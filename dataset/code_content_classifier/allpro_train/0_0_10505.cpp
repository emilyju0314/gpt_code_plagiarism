#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char flag[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> flag[i][j];
        }
    }

    bool meetsStandard = true;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (flag[i][j] == flag[i+1][j]) {
                meetsStandard = false;
            }
        }
    }

    if (meetsStandard) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}