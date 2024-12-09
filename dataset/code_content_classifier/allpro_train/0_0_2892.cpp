#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long countWays(vector<long long>& boxes, int s, int n, int idx, long long sum) {
    if (idx >= n) {
        if (sum == s) {
            return 1;
        }
        return 0;
    }

    long long totalWays = 0;
    for (int i = 0; i <= boxes[idx]; i++) {
        totalWays = (totalWays + countWays(boxes, s, n, idx + 1, sum + i)) % MOD;
    }

    return totalWays;
}

int main() {
    int n, s;
    cin >> n >> s;

    vector<long long> boxes(n);
    for (int i = 0; i < n; i++) {
        cin >> boxes[i];
    }

    long long ways = countWays(boxes, s, n, 0, 0);

    cout << ways << endl;

    return 0;
}