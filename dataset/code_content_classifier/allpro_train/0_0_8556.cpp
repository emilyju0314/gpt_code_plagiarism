#include <iostream>
using namespace std;

#define MOD 1000000007

int main() {
    int N, K;
    cin >> N >> K;
    
    long long ans = K;
    if(N > 1) {
        ans = (ans * K) % MOD;
    }
    if(N > 2) {
        long long tmp = 1;
        for(int i = 0; i < N-1; i++) {
            tmp = (tmp * K) % MOD;
        }
        ans = (ans * tmp) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}