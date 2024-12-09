#include <bits/stdc++.h>
#define LL long long
using namespace std;
map<long long,long long> mp;
const int maxn = 1e5 + 10;
int arr[maxn];
int main()
{
    int t;
    cin >> t;
    int n;
    LL res = 0;
    LL ans = 0;
    while(t--){
        cin >> n;
        ans = 0;
        res = 0;
        for(int i = 1 ; i <= n ; ++i){
            cin >> arr[i];
        }
        for(int i = 1 ; i <= n ; ++i){
            res += mp[arr[i]];
            mp[arr[i]] += i;
            ans += res;
        }
        mp.clear();
        cout << ans << endl;
    }
    return 0;
}
