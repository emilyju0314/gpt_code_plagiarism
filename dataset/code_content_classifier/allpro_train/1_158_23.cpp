#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 100000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vp;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a/gcd(a,b)*b;
}

#define MAX 3000

int ans = INF;
vp v;
int ncr[MAX][MAX];

void f(int sx, int sy, int gx, int gy){
    int dist = abs(sx-gx) + abs(sy-gy);
    if(dist > ans)return;
    if(dist < ans){
        ans = dist;
        v.clear();
    }
    v.push_back(pii(abs(sx-gx),abs(sy-gy)));
}

signed main(void) {
    int r,c;
    cin >> r >> c;
    int sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    f(r+sx,c+sy,gx,gy);
    f(r+sx,c+sy,gx,c+gy);
    f(r+sx,c+sy,gx,c+c+gy);
    f(r+sx,c+sy,r+gx,gy);
    f(r+sx,c+sy,r+gx,c+gy);
    f(r+sx,c+sy,r+gx,c+c+gy);
    f(r+sx,c+sy,r+r+gx,gy);
    f(r+sx,c+sy,r+r+gx,c+gy);
    f(r+sx,c+sy,r+r+gx,c+c+gy);
    ncr[0][0] = 1;
    rep(i,MAX)rep(j,MAX){
        if(i) ncr[i][j] = (ncr[i][j] + ncr[i - 1][j]) % MOD;
        if(i && j) ncr[i][j] = (ncr[i][j] + ncr[i - 1][j - 1]) % MOD;
    }
    int ans = 0;
    rep(i,v.size()){
        int x = v[i].first;
        int y = v[i].second;
        (ans += ncr[x+y][x]) %= MOD;
    }
    cout << ans << endl;
}

