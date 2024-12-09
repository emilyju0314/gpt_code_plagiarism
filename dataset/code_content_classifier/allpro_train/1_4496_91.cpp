#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

// U,R,D,L
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
string Q;
bool rec(pii n,int d,int cnt,vector<vector<char>>& masu){
    if(cnt == 0){
        return true;
    }
    for(int k = -1; k <= 1; k++){
        int nk = (d+k+4)%4;
        
        int nx,ny; tie(nx,ny) = n;
        bool find = false;
        while(true){
            nx += dx[nk];
            ny += dy[nk];
            if(masu[nx][ny] == '#') break;
            if(masu[nx][ny] == 'o'){
                find = true;
                break;
            }
        }
        if(find){
            masu[nx][ny] = '.';
            Q.push_back(nk==0?'U':nk==1?'R':nk==2?'D':'L');
            if(rec(pii(nx,ny),nk,cnt-1,masu)) return true;
            Q.pop_back();
            masu[nx][ny] = 'o';
        }
    }
    return false;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll H,W; cin >> H >> W;
    vector<vector<char>> masu(H+2,vector<char>(W+2,'#'));
    pii S;
    int dir = 0;
    int cnt = 0;
    for(int i = 1; i <= H;i++) for(int j = 1; j <= W;j++){
        cin >> masu[i][j];
        if(masu[i][j] == 'U'){
            S = {i,j};
            dir = 0;
            masu[i][j] = '.';
        }
        if(masu[i][j] == 'R'){
            S = {i,j};
            dir = 1;
            masu[i][j] = '.';
        }
        if(masu[i][j] == 'D'){
            S = {i,j};
            dir = 2;
            masu[i][j] = '.';
        }
        if(masu[i][j] == 'L'){
            S = {i,j};
            dir = 3;
            masu[i][j] = '.';
        }
        cnt += masu[i][j] == 'o';
    }
    rec(S,dir,cnt,masu);
    cout << Q << endl;
    return 0;
}

