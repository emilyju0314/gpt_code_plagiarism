#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int x, k, y;
    cin >> x >> k >> y;

    vector<int> original(n);
    vector<int> target(m);

    for (int i = 0; i < n; i++) {
        cin >> original[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> target[i];
    }

    unordered_map<int, int> target_pos;
    for (int i = 0; i < m; i++) {
        target_pos[target[i]] = i;
    }

    int ans = 0;

    vector<int> dangerous;
    for (int i = 0; i < n; i++) {
        if (target_pos.count(original[i])) {
            dangerous.push_back(original[i]);
        }
    }

    if (dangerous.size() < m) {
        cout << "-1" << endl;
        return 0;
    }

    vector<int> prefix_sum(m + 1, 0);
    for (int i = 0; i < m; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + (target_pos[dangerous[i]] < target_pos[dangerous[i - 1]]);
    }

    reverse(dangerous.begin(), dangerous.end());

    int cnt = 0;
    for (int i = 0; i < m; i++, cnt++) {
        if (dangerous[i] == target[cnt]) {
            continue;
        }

        int j = i - 1;
        while (j >= 0 && dangerous[i] != target[cnt]) {
            j--;
            cnt++;
        }

        if (j < 0) {
            cout << "-1" << endl;
            return 0;
        }

        ans += x;

        for (int index = j + 1; index <= i; index++) {
            if (prefix_sum[target_pos[dangerous[index]]] > prefix_sum[target_pos[dangerous[j]]) - 1) {
                cout << "-1" << endl;
                return 0;
            }
        }

        if (target_pos[dangerous[i]] != target_pos[dangerous[j]] + 1) {
            ans += y;
        }
    }

    cout << ans << endl;

    return 0;
}