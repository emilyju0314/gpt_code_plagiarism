#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mod 1000000007
#define inf 1e18
#define N 1000043
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define loop(a,b) for(int i=a;i<b;i++)
#define test int t; cin >> t; while(t--)
#define pll pair<ll,ll>
#define int ll
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test{
        int n,l,r;
        cin >> n >> l >> r;
        int l0=l,r0=r;
        vector<int>vec(n);
        loop(0,n) cin >> vec[i];
        map<int,int>le,re;
        for(int i=0;i<l;i++){
            le[vec[i]]++;
        }
        for(int i=l;i<n;i++){
            re[vec[i]]++;
        }
        int cnt=0,ans=0;
        for(int i=0;i<l;i++){
            if(re[vec[i]]!=0){
                re[vec[i]]--;
                cnt++;
                le[vec[i]]--;
                l0--;r0--;
            }
        }
        int c1=0,c2=0;
            for(auto it:re){
                int p=(it.s)/2;
                c1+=p;
            }
            for(auto it:le){
                int p=(it.s)/2;
                c2+=p;
            }
        ans+=(min(l0,r0));
        cnt+=(min(l0,r0));
        if(l0>r0){
            int d=l0-r0;
            d/=2;
            if(c2>=d)   ans+=d;
            else ans=ans+c2+(n/2-cnt-c2)*2;
        }else if(l0<r0){
            int d=r0-l0;
            d/=2;
            if(c1>=d)   ans+=d;
            else ans=ans+c1+(n/2-cnt-c1)*2;
        }
        cout << ans << endl;
    }
}

