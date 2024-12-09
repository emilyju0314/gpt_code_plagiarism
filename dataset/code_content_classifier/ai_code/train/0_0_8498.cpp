#include <iostream>
using namespace std;

int main() {
    long long n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < q; i++) {
        int s_x, s_y, e_x, e_y;
        cin >> s_x >> s_y >> e_x >> e_y;

        if (s_x == e_x) {
            cout << "YES" << endl;
        } else {
            if (n % 2 == 0 && m % 2 == 0) {
                cout << "YES" << endl;
            } else {
                if (s_y == e_y) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }

    return 0;
}