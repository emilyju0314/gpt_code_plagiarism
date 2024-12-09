#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> count;
    int distinct_count = 0;
    int l = 0, r = 0;
    int ans_l = -1, ans_r = -1;

    while (r < n) {
        if (count[a[r]] == 0) {
            distinct_count++;
        }
        count[a[r]]++;

        while (distinct_count > k) {
            count[a[l]]--;
            if (count[a[l]] == 0) {
                distinct_count--;
            }
            l++;
        }

        if (distinct_count == k) {
            if ((ans_l == -1 && ans_r == -1) || r - l < ans_r - ans_l) {
                ans_l = l;
                ans_r = r;
            }
        }

        r++;
    }

    cout << ans_l + 1 << " " << ans_r + 1 << endl;

    return 0;
}