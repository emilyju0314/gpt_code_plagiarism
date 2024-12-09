#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    long long s_sum = 0, t_sum = 0;
    for (int i = 0; i < n; i++) {
        s_sum += s[i];
        t_sum += t[i];
    }

    if (s_sum != t_sum) {
        cout << "NO" << endl;
        return 0;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    vector<pair<int, pair<int, int>>> moves;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (s[i] < t[j]) {
            int d = min(t[j] - s[i], s[i + 1] - s[i]);
            moves.push_back({i+1, j+1, d});
            s[i] += d;
            s[i + 1] -= d;
            if (s[i] == t[j]) {
                i++;
            }
        } else if (s[i] > t[j]) {
            int d = min(s[i] - t[j], t[j + 1] - t[j]);
            moves.push_back({i+1, j+1, d});
            t[j] += d;
            t[j + 1] -= d;
            if (s[i] == t[j]) {
                j++;
            }
        } else {
            i++;
            j++;
        }
    }

    cout << "YES" << endl;
    cout << moves.size() << endl;
    for (auto move : moves) {
        cout << move.first << " " << move.second << " " << move.second << endl;
    }

    return 0;
}