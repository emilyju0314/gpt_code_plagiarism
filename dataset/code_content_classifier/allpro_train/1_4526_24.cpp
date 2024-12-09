#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include<cstdio>

using namespace std;
const int maxn= 2e5+50;
const long long mod=1e9+7;
typedef long long ll;

#define INF 9999999999
#define rep(i, a, n) for(int i = a; i <= n; i ++)
#define pre(i, n, a) for(int i = n; i >= a; i --)
#define IOS ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define mem(a,t) memset(a,t,sizeof(a))
#define debug(a) cout<<#a<<"="<<a<<endl;
#define pb(a)  push_back(a)
#define lson root<< 1
#define rson root << 1 | 1

inline ll read(){ ll f = 1; ll x = 0;char ch = getchar();while(ch>'9'||ch<'0') {if(ch=='-') f=-1; ch = getchar();}while(ch>='0'&&ch<='9') x = (x<<3) + (x<<1) + ch - '0',  ch = getchar();return x*f; }

priority_queue <int,vector<int>,greater<int> > que;
priority_queue <int,vector<int>,less<int> >que2;
struct node{
    ll sum;
    int id;
    bool operator <(const node &x)const
    {
        return sum > x.sum;
    }
};
priority_queue<node>que3;

ll a[maxn];
ll dp[maxn];
int main(){
int t;
cin>>t;
while(t--){
    int n;
    ll sum=0;
    cin>>n;
    rep(i,1,n)cin>>a[i],sum+=a[i];
    if(sum%n!=0)
    {
        cout<<-1<<endl;
        continue;
    }
    ll ava=sum/n;
    ll ans=0;
    ll cnt=0;
    sum=0;
    rep(i,1,n)
    {
        if(a[i]>ava)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    


}







return 0;
}
