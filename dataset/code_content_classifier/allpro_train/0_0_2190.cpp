#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> segments(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        segments[i] = {l, r};
    }

    vector<int> count(n - k + 1, 0);
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j < m; j++) {
            if (segments[j].first <= i + k && segments[j].second >= i + 1) {
                count[i]++;
            }
        }
    }

    int max_sum = 0;
    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            if (segments[j].second >= i + 1 && segments[j].first <= i + k) {
                sum++;
            }
        }
        max_sum = max(max_sum, sum);
    }

    cout << max_sum << endl;

    return 0;
}