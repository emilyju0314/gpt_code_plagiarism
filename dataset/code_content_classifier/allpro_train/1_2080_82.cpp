#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int sum[1002][1002];
int main(){
    int n;
    cin>>n;
    int x1,y1,x2,y2;
    rep(i,n){
        cin>>x1>>y1>>x2>>y2;
        ++x1,++y1,++x2,++y2;
        ++sum[y1][x1],++sum[y2][x2];
        --sum[y2][x1],--sum[y1][x2];
    }
    int mx=0;
    FOR(i,1,1002)FOR(j,1,1002){
        sum[i][j]+=sum[i-1][j];
        sum[i][j]+=sum[i][j-1];
        sum[i][j]-=sum[i-1][j-1];
        mx=max(mx,sum[i][j]);
    }
    cout<<mx<<endl;
    return 0;
}
