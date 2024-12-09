#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    string s, t;
    cin >> s >> t;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        int count = 0;
        for (int j = l-1; j <= r-m; j++) {
            bool found = true;
            for (int k = 0; k < m; k++) {
                if (s[j+k] != t[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}