#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int main() {
    int k, n, m;
    cin >> k >> n >> m;

    vector<pair<int, int>> arkady(n), kirill(m);

    for (int i = 0; i < n; i++) {
        cin >> arkady[i].first >> arkady[i].second;
    }

    for (int i = 0; i < m; i++) {
        cin >> kirill[i].first >> kirill[i].second;
    }

    sort(arkady.begin(), arkady.end());
    sort(kirill.begin(), kirill.end());

    long long ans = 1;

    int obverse = 0, reverse = 0, obverse_required = 0, reverse_required = 0;

    for (int i = 0, j = 0; i < n || j < m;) {
        if (i < n && (j == m || arkady[i].first < kirill[j].first)) {
            if (++obverse > arkady[i].second) {
                ans = 0;
                break;
            }
            if (reverse_required > 0) {
                obverse_required++;
            }
            i++;
        } else {
            if (++reverse > kirill[j].second) {
                ans = 0;
                break;
            }
            if (obverse_required > 0) {
                reverse_required++;
            }
            j++;
        }

        if (i < n && arkady[i].first == obverse) {
            obverse_required++;
        }

        if (j < m && kirill[j].first == reverse) {
            reverse_required++;
        }

        if (obverse_required > 0 && reverse_required > 0) {
            obverse_required--;
            reverse_required--;
            ans *= (min(obverse, reverse) - max(obverse_required, reverse_required));
            ans %= MOD;
        }
    }

    if (obverse != reverse) {
        ans = 0;
    }

    cout << ans << endl;

    return 0;
}