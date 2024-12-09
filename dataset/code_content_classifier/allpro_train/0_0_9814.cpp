#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int k = 0;
    int score_f = 0;
    int score_s = 0;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int pos, x;
            cin >> pos >> x;
            a[pos-1] = x;
        } else if (type == 2) {
            int pos, x;
            cin >> pos >> x;
            b[pos-1] = x;
        } else {
            cin >> k;

            vector<int> first_team(n), second_team(m);
            for (int j = 0; j < n; j++) {
                first_team[j] = max(k + a[j] - k, 0);
            }
            for (int j = 0; j < m; j++) {
                second_team[j] = max(k + b[j] - k, 0);
            }

            sort(first_team.rbegin(), first_team.rend());
            sort(second_team.rbegin(), second_team.rend());

            for (int j = 0; j < min(n, m); j++) {
                score_f += first_team[j];
                score_s += second_team[j];
            }

            cout << score_f - score_s << endl;
        }
    }

    return 0;
}