#include <iostream>
using namespace std;
typedef long long ll;
ll GCD(ll a, ll b) {
    return (a == 0) ? b : GCD(b % a, a);
}
ll LCM(ll a, ll b) {
    return a * b / GCD(a, b);
}
int main() {
    int a[3], m[3];
    while (1) {
        cin >> a[0] >> m[0] >> a[1] >> m[1] >> a[2] >> m[2];
        if (!a[0]) {
            break;
        }
        int val[3] = {1,1,1}, move[3] = {0};
        int cnt = 0;
        for (int i=1; ; ++i) {
            for (int j=0; j<3; ++j) {
                if (move[j]) continue;
                val[j] = a[j] * val[j] % m[j];
                if (val[j] == 1) {
                    move[j] = i;
                    cnt ++;
                }
            }
            if (cnt >= 3) break;
        }
        ll ans = LCM(LCM(move[0], move[1]), move[2]);
        cout << ans << endl;
    }
}