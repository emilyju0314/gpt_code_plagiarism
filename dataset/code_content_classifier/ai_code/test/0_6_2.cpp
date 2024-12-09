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

    long long answer = 0;
    if (k == 1) {
        answer = (long long)n * (m * (m + 1) / 2) % MOD;
    } else {
        unordered_map<int, int> count;
        int sum = 0;
        count[0] = 1;

        for (int i = 0; i < n; i++) {
            sum += a[i];
            sum %= k;
            count[sum]++;
        }

        for (auto it : count) {
            answer += (long long)it.second * (it.second - 1) / 2;
            answer %= MOD;
        }

        for (int i = 0; i < n; i++) {
            sum += a[i];
            sum %= k;
            count[sum]--;

            answer += (long long)count[sum] * m;
            answer %= MOD;
        }
    }

    cout << answer << endl;

    return 0;
}