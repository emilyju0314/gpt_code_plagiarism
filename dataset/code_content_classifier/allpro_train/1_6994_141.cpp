#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int N, x;
    int a, p;
    ll ans = 0;
    cin >> N >> x;
    cin >> p;
    for(int i = 1; i < N; i++){
        cin >> a;
        if(p+a > x){
            ans += (p+a) - x;
            a -= min(a, (p+a) - x);
        }
        p = a;
    }
    cout << ans << endl;
    return 0;
}
