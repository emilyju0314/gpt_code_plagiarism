#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            cnt++;
        }
    }

    long long total_ways = 1;
    for (int i = 0; i < cnt; i++) {
        total_ways = (total_ways * k) % MOD;
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (a[i] != -1 && a[i] != j) {
                long long num_ways = total_ways;
                if (a[i] == -1) {
                    num_ways = (num_ways * k) % MOD;
                }
                result = (result + num_ways) % MOD;
            }
        }
    }

    cout << result << endl;

    return 0;
}