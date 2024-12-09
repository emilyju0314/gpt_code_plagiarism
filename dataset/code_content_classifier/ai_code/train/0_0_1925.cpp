#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    string initial, ideal;
    cin >> initial >> ideal;

    vector<pair<int, int>> swaps(n);
    for (int i = 0; i < n; i++) {
        cin >> swaps[i].first >> swaps[i].second;
    }

    int max_same_pie = 0;
    int start_idx;
    for (int i = 0; i <= n - m; i++) {
        vector<int> revised(k);
        for (int j = 0; j < k; j++) {
            revised[j] = initial[j] == ideal[j] ? 1 : 0;
        }
        int same_pie = 0;
        for (int j = i; j < i + m; j++) {
            int a = swaps[j].first - 1;
            int b = swaps[j].second - 1;
            if (initial[a] == ideal[b]) {
                same_pie++;
            }
            if (initial[b] == ideal[a]) {
                same_pie++;
            }
        }
        if (same_pie > max_same_pie) {
            max_same_pie = same_pie;
            start_idx = i;
        }
    }

    cout << max_same_pie << endl;
    cout << start_idx + 1 << " " << start_idx + m << endl;

    return 0;
}