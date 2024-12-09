#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000007

int main() {
    int q;
    cin >> q;

    while(q--) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;

        long long ans = 0;
        for(int i = x1; i <= x2; i++) {
            for(int j = y1; j <= y2; j++) {
                if((i+j)%k < k) {
                    ans += (i+j)%k;
                    ans %= MOD;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}