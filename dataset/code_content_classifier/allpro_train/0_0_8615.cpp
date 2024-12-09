#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<int> stamps(n);
    for (int i = 0; i < n; ++i) {
        cin >> stamps[i];
    }

    unordered_map<int, long long> count;
    for (int i = 0; i < n; ++i) {
        for (int j = 2; j * j <= stamps[i]; ++j) {
            if (stamps[i] % j == 0) {
                count[j]++;
                if (j * j != stamps[i]) {
                    count[stamps[i] / j]++;
                }
            }
        }
        count[stamps[i]]++;
    }

    long long total = 0;
    for (int i = 0; i < n; ++i) {
        total += n - count[stamps[i]];
    }

    cout << total % MOD << endl;

    return 0;
}