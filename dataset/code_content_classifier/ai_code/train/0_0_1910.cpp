#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            long long d;
            cin >> d;
            for (int i = l-1; i < r; i++) {
                a[i] += d;
            }
        } else {
            bool first_player_wins = false;
            for (int i = l-1; i < r; i++) {
                if (a[i] >= r-l+1) {
                    first_player_wins = true;
                    break;
                }
            }

            if (first_player_wins) {
                cout << "1\n";
            } else {
                cout << "2\n";
            }
        }
    }

    return 0;
}