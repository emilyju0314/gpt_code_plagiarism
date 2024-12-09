#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i + j) % 2 == 0) {
                b[i][j] = a[i][j] * a[i][j] * a[i][j] * a[i][j];
            } else {
                b[i][j] = a[i][j] * a[i][j] * a[i][j] * a[i][j] + 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}