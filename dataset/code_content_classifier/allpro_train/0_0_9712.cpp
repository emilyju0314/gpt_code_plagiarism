#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if(n == 1 && m == 1) {
        cout << "1 1" << endl;
    } else if (n == 1) {
        for(int j = 1; j <= m; j++) {
            cout << "1 " << j << endl;
        }
    } else if (m == 1) {
        for(int i = 1; i <= n; i++) {
            cout << i << " 1" << endl;
        }
    } else {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(i % 2 == 1) {
                    cout << i << " " << j << endl;
                } else {
                    cout << i << " " << (m+1-j) << endl;
                }
            }
        }
    }

    return 0;
}