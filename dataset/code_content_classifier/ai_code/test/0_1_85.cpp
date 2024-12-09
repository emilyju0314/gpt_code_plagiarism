#include <iostream>
#include <vector>

using namespace std;

int power(int x, int n, int M) {
    if (n == 0) return 1;
    long long res = power(x, n/2, M);
    res = (res * res) % M;
    if (n % 2 == 1) res = (res * x) % M;
    return res;
}

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> fact(n+2, 1);
    for (int i = 1; i <= n+1; i++) {
        fact[i] = (fact[i-1] * i) % M;
    }

    int ans = 0;
    for (int i = 2; i <= n+1; i++) {
        int temp = (fact[n+1] * power(fact[i], M-2, M) * power(fact[n+1-i+1], M-2, M)) % M;
        ans = (ans + temp) % M;
    }

    cout << ans << endl;

    return 0;
}