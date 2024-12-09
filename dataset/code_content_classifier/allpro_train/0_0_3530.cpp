#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int power(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> primes;
    int temp = M;
    for (int i = 2; i * i <= M; i++) {
        while (temp % i == 0) {
            primes.push_back(i);
            temp /= i;
        }
    }
    if (temp > 1) {
        primes.push_back(temp);
    }

    int ans = 1;
    for (int p : primes) {
        int cnt = 0;
        while (M % p == 0) {
            M /= p;
            cnt++;
        }
        ans = (ans * power(N + cnt - 1, N - 1)) % MOD;
    }

    cout << ans << endl;

    return 0;
}