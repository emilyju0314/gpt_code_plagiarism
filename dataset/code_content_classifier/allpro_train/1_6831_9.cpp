#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <fstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<P> vp;
#define rep(i,a,n) for(ll i = (a);i < (n);i++)
#define per(i,a,n) for(ll i = (a);i > (n);i--)
#define lep(i,a,n) for(ll i = (a);i <= (n);i++)
#define pel(i,a,n) for(ll i = (a);i >= (n);i--)
#define clr(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz size()
#define endl "\n"
#define print(X) cout << (X) << "\n"
// #define input(X) getline(cin,X)
static const ll  INF = 1e9+7;
static const ll INFL = 1e18+7;
ll n,m,l, p;
string s,t;
ll d[200010],e[200010],dp[1001][1001];
char field[202][202];

char piece[6][8][10][10];
char box[10][10][10];

#define NONE 0

void init(){
    clr(piece, NONE);
    clr(box, NONE);
}

void lotate(char p[10][10], int index,int pn){
    if(index == 8)return;
    rep(x,0,n)
        rep(y,0,n)
            piece[pn][index][y][n-x-1] = p[x][y];
        
    lotate(piece[pn][index], index+1, pn);
}

void reverse(int index, int pn){
    if(index == 8)return;
    rep(x,0,n)
        rep(y,0,n/2)
            swap(piece[pn][index][x][y], piece[pn][index][x][n-y-1]);

    reverse(index+1, pn);
}

void input(){
    rep(i,0,6){
        char p[10][10];
        rep(y,0,n)scanf("%s",p[y]);

        lotate(p, 0, i);
        reverse(4, i);
    }
}

void getPiece(char p[10][10], int pi, int state){
    rep(x,0,n)
        rep(y,0,n)
            p[x][y] = piece[pi][state][x][y];
}

void getPoint(int &xa, int &ya,int &za, int &xb, int &yb,int &zb, int sf){
    sf += 1;

    xa = 0,   ya = 0,   za = 0;
    xb = n,   yb = n,   zb = n;

    if     (sf == 1)  zb = 0+1;
    else if(sf == 2)  xb = 0+1;
    else if(sf == 3)  za = n-1;
    else if(sf == 4)  xa = n-1;
    else if(sf == 5)  ya = n-1;
    else  /*sf == 6*/ yb = 0+1;
}

bool check(){
    int xa, ya, za;
    int xb, yb, zb;
    rep(i,0,6){
        getPoint(xa, ya, za, xb, yb, zb, i);
        rep(x, xa, xb)
            rep(y,ya, yb)
                rep(z, za, zb)
                    if(box[x][y][z] != 'X')return false;
    }

    return true;
}

bool setting(int pi, int state, int sf){
    char p[10][10];
    int xa, ya, za;
    int xb, yb, zb;

    getPiece(p, pi, state);
    getPoint(xa, ya, za, xb, yb, zb, sf);

    rep(x, xa, xb){
        rep(y,ya, yb){
            rep(z, za, zb){
                if     (sf==0 || sf==2)  {if(box[x][y][z] == 'X' && p[x][y] == 'X')return false;}
                else if(sf==1 || sf==3)  {if(box[x][y][z] == 'X' && p[y][z] == 'X')return false;}
                else /* sf==5 || sf==6 */{if(box[x][y][z] == 'X' && p[x][z] == 'X')return false;}
            }
        }
    }

    // ok
    rep(x, xa, xb){
        rep(y,ya, yb){
            rep(z, za, zb){
                if     (sf==0 || sf==2)  {if(p[x][y] == 'X')box[x][y][z] = p[x][y];}
                else if(sf==1 || sf==3)  {if(p[y][z] == 'X')box[x][y][z] = p[y][z];}
                else /* sf==5 || sf==6 */{if(p[x][z] == 'X')box[x][y][z] = p[x][z];}
            }
        }
    }

    return true;
}

void undo(int pi, int state, int sf){
    char p[10][10];
    int xa, ya, za;
    int xb, yb, zb;
    getPiece(p, pi, state);
    getPoint(xa, ya, za, xb, yb, zb, sf);

    rep(x, xa, xb){
        rep(y,ya, yb){
            rep(z, za, zb){
                if     (sf==0 || sf==2)  {if(p[x][y] == 'X')box[x][y][z] = NONE;}
                else if(sf==1 || sf==3)  {if(p[y][z] == 'X')box[x][y][z] = NONE;}
                else /* sf==5 || sf==6 */{if(p[x][z] == 'X')box[x][y][z] = NONE;}
            }
        }
    }
}

bool dfs(int depth){
    if(depth > 5)return check();

    rep(state,0,8){
        rep(place,1,6){
            if(setting(depth, state, place)){
                if(dfs(depth+1))return true;
                undo(depth, state, place);
            }
        }
    }
    return false;
}

int main() {
    while(cin >> n,n){
        init();
        input();
        setting(0, 0, 0);
        if(dfs(1))puts("Yes");
        else puts("No");
    }
    return 0;
}

