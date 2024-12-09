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
#define MOD 1000000007
#define rep(i,n) for(i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

#define max_n 100

int v[max_n][max_n]; //上面にかかれた数
int h[max_n][max_n]; //サイコロの高さ
int geta = max_n/2; //中央(geta,geta)
int p[7][7] = {};

void fall(int x, int y, int top, int front, int side){

    for(int i = 6; i >= 4; i--){
        if(top != i && top != 7-i){//iが側面にある
            if(front == i){
                if(h[x-1][y] >= h[x][y])continue;
                fall(x-1, y, 7-front, top, p[7-front][top]);
            }else if(front == 7-i){
                if(h[x+1][y] >= h[x][y])continue;
                fall(x+1, y, front, 7-top, p[front][7-top]);
            }else if(side == i){
                if(h[x][y+1] >= h[x][y])continue;
                fall(x, y+1, 7-side, front, top);
            }else if(side == 7-i){
                if(h[x][y-1] >= h[x][y])continue;
                fall(x, y-1, side, front, 7-top);
            }
            return;
        }
    }


    h[x][y]++;
    v[x][y] = top;
}

int main(void) {
    int i,j;
    int n;

    p[1][2] = 3;
    p[1][3] = 5;
    p[1][4] = 2;
    p[1][5] = 4;

    p[2][1] = 4;
    p[2][3] = 1;
    p[2][4] = 6;
    p[2][6] = 3;

    p[3][1] = 2;
    p[3][2] = 6;
    p[3][5] = 1;
    p[3][6] = 5;

    p[4][1] = 5;
    p[4][2] = 1;
    p[4][5] = 6;
    p[4][6] = 2;

    p[5][1] = 3;
    p[5][3] = 6;
    p[5][4] = 1;
    p[5][6] = 4;

    p[6][2] = 4;
    p[6][3] = 2;
    p[6][4] = 5;
    p[6][5] = 3;

    while(cin >> n, n){
        rep(i,max_n)rep(j,max_n){
            v[i][j] = 0;
            h[i][j] = 0;
        }

        rep(i,n){
            int t,f;
            cin >> t >> f;

            fall(geta,geta,t,f,p[t][f]);

        }

        vi ans(6,0);
        rep(i,max_n)rep(j,max_n)if(v[i][j] >= 1 && v[i][j] <= 6){
            ans[v[i][j] - 1]++;
        }

        rep(i,6){
            cout << ans[i];
            if(i<5) cout << " ";
            else cout << endl;
        }

    }
}

