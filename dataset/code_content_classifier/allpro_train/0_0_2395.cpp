#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    long long totalSum = 0;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        long long numSubsets = 1 << i;
        sum = (sum * 2) % MOD;
        sum = (sum + MOD - (numSubsets - 1) * x[i]) % MOD;
        totalSum = (totalSum + sum) % MOD;
    }

    cout << totalSum << endl;

    return 0;
}