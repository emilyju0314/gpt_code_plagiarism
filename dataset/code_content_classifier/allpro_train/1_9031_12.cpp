#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);

void dfs(ll u, vector<ll> & dp,string & st){
    ll n=dp.size();
    if(2*u+1>=n-1){
        if(st[u]=='?'){
            dp[u]=2;
        }
        else{
            dp[u]=1;
        }
        return;
    }
    dfs(2*u+1,dp,st);
    dfs(2*u+2,dp,st);
    if(st[u]=='?'){
        dp[u]=dp[2*u+1]+dp[2*u+2];
    }
    else if(st[u]=='0'){
        dp[u]=dp[2*u+2];
    }
    else{
        dp[u]=dp[2*u+1];
    }
}

void solve(){
    ll k;
    cin>>k;
    ll n=1<<k;
    string st;
    cin>>st;
    if(k==1){
        ll q;
        cin>>q;
        while(q--){
            ll p;
            cin>>p;
            char c;
            cin>>c;
            if(c=='?'){
                cout<<2<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }
        return;
    }
    reverse(st.begin(),st.end());
    vector<ll> dp(n);
    dfs(0,dp,st);
    ll q;cin>>q;
    while(q--){
        ll p;
        cin>>p;
        p=n-p-1;
        char c;
        cin>>c;
        st[p]=c;
        while(p>0){
            if(2*p+1>=n-1){
                if(st[p]=='?'){
                    dp[p]=2;
                }
                else{
                    dp[p]=1;
                }
            }
            else{
                if(st[p]=='?'){
                    dp[p]=dp[2*p+1]+dp[2*p+2];
                }
                else if(st[p]=='0'){
                    dp[p]=dp[2*p+2];
                }
                else{
                    dp[p]=dp[2*p+1];
                }
            }
            p=(p-1)/2;
        }
        if(st[0]=='?'){
            dp[0]=dp[1]+dp[2];
        }
        else if(st[0]=='0'){
            dp[0]=dp[2];
        }
        else{
            dp[0]=dp[1];
        }
        cout<<dp[0]<<endl;
    }
}

int main(){
    FAST1;
    FAST2;
    ll t=1;
    while(t--){
        solve();
    }
}