#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if(n == 1 && m == 1) {
        cout << 1 << endl;
    } else if(n == 1 || m == 1) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << i*m + j << " ";
            }
            cout << endl;
        }
    } else if(n % 2 == 1 && m % 2 == 1) {
        int height = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << height << " ";
                height += 2;
            }
            cout << endl;
        }
    } else if(n % 2 == 1 || m % 2 == 1) {
        if(n % 2 == 1) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    cout << i*m - (j-1) << " ";
                }
                cout << endl;
            }
        } else {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    cout << j*n - (i-1) << " ";
                }
                cout << endl;
            }
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}