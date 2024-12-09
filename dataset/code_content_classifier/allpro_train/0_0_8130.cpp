#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, S, W, Q;
    
    while (cin >> N >> S >> W >> Q) {
        if (N == 0 && S == 0 && W == 0 && Q == 0) {
            break;
        }
        
        vector<int> a(N);
        int g = S;
        
        for(int i = 0; i < N; i++) {
            a[i] = (g/7) % 10;
            if (g % 2 == 0) {
                g = (g/2);
            } else {
                g = (g/2) ^ W;
            }
        }
        
        long long ans = 0;
        int curr = 0;
        vector<int> mods(Q, 0);
        
        mods[0] = 1;
        for (int i = N - 1; i >= 0; i--) {
            curr = (curr + a[i] * mods[0]) % Q;
            ans += mods[curr];
            mods[curr]++;
            mods[curr] %= Q;
            for (int j = 0; j < Q; j++) {
                mods[j] = (mods[j] + mods[j + curr]) % Q;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}