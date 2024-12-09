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
    long long ans = 0;
    int cur = 0;
    count[0] = 1;

    for (int i = 0; i < n; i++) {
        if (count.find(a[i]) != count.end()) {
            cur = max(cur, count[a[i]]);
            ans += cur - k;
        }
        count[a[i]] = i + 1;
    }

    cout << ans << endl;

    return 0;
}