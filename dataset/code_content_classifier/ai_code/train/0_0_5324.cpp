#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, long long> count;
    count[0] = 1;
    long long ans = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans += count[sum - k];
        count[sum]++;
    }

    cout << ans << endl;

    return 0;
}