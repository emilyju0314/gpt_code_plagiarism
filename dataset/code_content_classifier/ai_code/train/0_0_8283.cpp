#include <iostream>
#include <vector>

using namespace std;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    int N, M, a;
    long long Q;
    cin >> N >> M >> a >> Q;
    
    vector<long long> A(N, a);
    
    long long mult_order = Q - 1;
    long long ans = 1;
    for (int i = 0; i < N; i++) {
        ans = (ans * A[i]) % Q;
    }
    long long exp = mod_pow(a, M, mult_order);
    ans = mod_pow(ans, exp, Q);
    
    for (int i = 0; i < N; i++) {
        if (i != N-1) {
            cout << (ans % Q) << " ";
        } else {
            cout << (ans % Q) << endl;
        }
        ans = (ans * mod_pow(A[i], 2, Q)) % Q;
    }
    
    return 0;
}