#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> left(n);
    vector<int> right(n);

    for (int i = 0; i < n; i++) {
        cin >> left[i] >> right[i];
    }

    vector<int> cnt(m + 2, 0);

    for (int i = 0; i < n; i++) {
        cnt[left[i]]++;
        cnt[right[i] + 1]--;
    }

    int prefix_sum = 0;
    vector<int> cnt2(m + 2, 0);

    for (int i = 1; i <= m; i++) {
        prefix_sum += cnt[i];
        if (prefix_sum > 0) {
            cnt2[i]++;
        }
    }

    for (int i = 1; i <= m; i++) {
        cnt2[i] += cnt2[i - 1];
    }

    int max_segments = *max_element(cnt2.begin(), cnt2.end());

    cout << max_segments << endl;

    return 0;
}