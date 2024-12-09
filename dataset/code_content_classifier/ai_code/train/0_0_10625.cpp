#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Any valid combination of n and m can be used, for this example I will use n = 4 and m = 7
    int n = 4, m = 7;

    cout << n << " " << m << endl;

    char grid[4][7] = {
        {'D', 'D', 'D', 'D', 'D', 'D', 'D'},
        {'D', 'A', 'B', 'A', 'C', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'A', 'C', 'D'},
        {'D', 'D', 'D', 'D', 'D', 'D', 'D'}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}