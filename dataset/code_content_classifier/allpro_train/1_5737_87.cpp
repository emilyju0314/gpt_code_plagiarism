#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], cnt[2];
int main()
{
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;++i){
        cin >> a[i];
        ++cnt[a[i]];
    }
    while(q--){
        int t,x;
        cin >> t >> x;
        if(t==1){
            cnt[a[x]]--;
            a[x] ^= 1;
            cnt[a[x]]++;
        }
        else{
            if(cnt[1]>=x)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}
