#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i=a; i<n; i++)
#define RREP(i, a, n) for(ll i=n-1; i>=a; i--)
typedef long long ll;
const ll mod =1e9+7;
const ll inf =1e18;
using namespace std;

ll n, m;
ll e[101010];
bool flag[202020];
vector<ll> ans;
int main(){
    cin>>n>>m;
    REP(i, 0, m) cin>>e[i];

    RREP(i, 0, m){
        if(!flag[e[i]]){
            ans.emplace_back(e[i]);
            flag[e[i]]=true;
        }
    }
    REP(i, 1, n+1){
        if(!flag[i]) ans.emplace_back(i);
    }

    REP(i, 0, ans.size()){
        cout<<ans[i]<<endl;
    }
    return 0;
}
