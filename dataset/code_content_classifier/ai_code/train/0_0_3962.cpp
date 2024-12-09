#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 998244353

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(int a, int b) {
    return (long long)a * b / gcd(a, b);
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> factorial(N+1, 1);
    for (int i = 1; i <= N; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }

    long long ans = 0;
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            ans = (ans + lcm(A[i], A[j])) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}