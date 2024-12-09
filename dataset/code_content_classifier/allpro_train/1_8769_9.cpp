#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << ": " << (x) << endl
#else
#define debug(x)
#endif
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int maxn=1e5+7,inf=0x3f3f3f3f,mod=1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase;
    cin>>kase;
    while(kase--)
    {
        int n;
        cin>>n;
        vi a,b;
        for(int i=0,x;i<n;++i)
        {
            cin>>x;
            if(i%2==0) a.push_back(x);
            else b.push_back(x);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vi ans;
        int c1=0,c2=0;
        for(int i=0;i<n;++i)
        {
            if(i%2==0) ans.push_back(a[c1++]);
            else ans.push_back(b[c2++]);
        }
        if(is_sorted(ans.begin(),ans.end())) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}