#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long total_cost = 0;
    for (int i = 0; i < n; i++) {
        total_cost = (total_cost + abs(arr[i] - arr[n/2])) % MOD;
    }

    if (n % 2 == 0 && arr[n/2-1] == arr[n/2]) {
        cout << power(2, n/2) << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}