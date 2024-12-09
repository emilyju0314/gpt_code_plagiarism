#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> l[i] >> r[i];
    }

    long long sum_a = 0, sum_l = 0, sum_r = 0;
    for (int i = 0; i < n; i++) {
        sum_a += a[i];
        sum_l += l[i];
        sum_r += r[i];
    }

    int ans = 0, ans_l = 0, ans_r = 0;
    for (int i = 0; i < n; i++) {
        if (sum_l - sum_r + a[i] > 0) {
            ans = max(ans, abs(sum_l - sum_r + a[i]));
            ans_l = max(ans_l, abs(sum_l - sum_r + a[i]) - (r[i] - a[i]));
            ans_r = max(ans_r, abs(sum_l - sum_r + a[i]) - (a[i] - l[i]));
        }
    }

    cout << max(ans_l, ans_r) + ans << endl;

    return 0;
}