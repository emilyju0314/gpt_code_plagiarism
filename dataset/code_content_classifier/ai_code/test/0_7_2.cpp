#include <iostream>
#include <vector>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long total = 0;
    long long sum = 0;
    unordered_map<int, int> count;
    count[0] = 1;

    for (int i = 0; i < n * m; i++) {
        sum = (sum + a[i % n]) % k;
        total += count[(k - sum) % k];
        count[sum]++;
        if (i >= n * m - n) {
            count[(sum - a[(i - n * m + n) % n] + k) % k]--;
        }
    }

    cout << total % MOD << endl;

    return 0;
}