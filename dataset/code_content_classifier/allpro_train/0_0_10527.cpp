#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    unordered_map<int, int> diff_freq;
    long long ans = 0;
    int diff = 0;

    for (int i = 0; i < n; i++) {
        diff += a[i] - b[i];
        if (diff == 0) {
            ans++;
        }
        ans += diff_freq[diff];
        diff_freq[diff]++;
    }

    cout << ans << endl;

    return 0;
}