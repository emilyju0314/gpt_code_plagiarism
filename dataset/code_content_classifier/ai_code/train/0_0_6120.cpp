#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353
#define MAXN 100001

using namespace std;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int N;
    cin >> N;

    vector<int> M1(N+1, 0), M2(N+1, 0), M3(N+1, 0);

    for (int i = 0; i < 3; i++) {
        int M;
        cin >> M;
        for (int j = 0; j < M; j++) {
            int a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            if (i == 0) M1[a] = M1[b] = 1;
            else if (i == 1) M2[a] = M2[b] = 1;
            else M3[a] = M3[b] = 1;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        if (M1[i] == 0) ans = (ans + power(10, 18 * i)) % MOD;
        if (M2[i] == 0) ans = (ans + power(10, 18 * i)) % MOD;
        if (M3[i] == 0) ans = (ans + power(10, 18 * i)) % MOD;
    }

    cout << ans << endl;

    return 0;
}