#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;
    
    int A[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A, A+N);
    
    long long ans = 1;
    if(A[N-1] == 0 && K % 2 != 0) {
        cout << 0 << endl;
    } else if(A[N-1] <= 0 && K % 2 != 0) {
        for(int i = N-1; i >= N-K; i--) {
            ans = (ans * A[i]) % MOD;
        }
        cout << (ans + MOD) % MOD << endl;
    } else {
        int l = 0, r = N-1;
        if(K % 2 != 0) {
            ans = A[r--];
            K--;
        }
        for(int i = 0; i < K/2; i++) {
            long long left = (long long)A[l]*A[l+1];
            long long right = (long long)A[r]*A[r-1];
            if(left > right) {
                ans = (ans * left) % MOD;
                l += 2;
            } else {
                ans = (ans * right) % MOD;
                r -= 2;
            }
        }
        cout << (ans + MOD) % MOD << endl;
    }
    return 0;
}