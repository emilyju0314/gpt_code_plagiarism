#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<long long, long long> count1, count2;
    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count2[a[i]]++;
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        count2[a[i]]--;

        if (a[i] % k == 0 && count1.count(a[i] / k) && count2.count(a[i] * k)) {
            ans += count1[a[i] / k] * count2[a[i] * k];
        }

        count1[a[i]]++;
    }

    cout << ans << endl;

    return 0;
}