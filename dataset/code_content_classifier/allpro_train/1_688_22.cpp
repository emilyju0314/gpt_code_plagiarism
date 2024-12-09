#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    ll sum=0;
    vector<ll>a(n);
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    sort(all(a));
    if(n%2){
        if(sum%2){
            cout<<"First"<<endl;
        }else{
            cout<<"Second"<<endl;
        }
    }else{
        if(a[0]%2)cout<<"First"<<endl;
        else if(sum%2)cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
}
