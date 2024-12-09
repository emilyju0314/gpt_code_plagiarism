#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> p(N);
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }
    
    long long ans = 1;
    for(int i = 1; i < N; i++) {
        if(p[i] < p[i - 1]) {
            ans = 0;
            break;
        }
    }
    
    if(ans == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    for(int i = 0; i < N - 1; i++) {
        ans = (ans * (i + 1)) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}