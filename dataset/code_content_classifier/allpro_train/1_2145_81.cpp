#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int u[216000];
bool loop[216000];
void init(){
    for(int i = 0;i < 216000;i++)u[i] = i;
}

int rt(int x){
    if(u[x] == x)return x;
    return u[x] = rt(u[x]);
}

void unite(int x, int y){
    x = rt(x);
    y = rt(y);
    u[x] = y;
}

int n, h, w;
int r, c, a;

typedef pair<Int, P> T;

vector<T> edges;
Int res;
int main(){
    init();
    cin >> n >> h >> w;
    for(int i = 0;i < n;i++){
        cin >> r >> c >> a;r--,c--;
        edges.push_back(T(a,P(r, c)));
    }
    sort(edges.rbegin(), edges.rend());
    for(auto e: edges){
        a = e.first;
        r = e.second.first;
        c = e.second.second;
        c += h;
        int rtr = rt(r), rtc = rt(c);
        if(loop[rtr] && loop[rtc])continue;
        res += a;
//        cout << a << " " << r + 1 << " " << c - n + 1 << endl;
        if(rtr == rtc){
            loop[rtr] = true;
            continue;
        }
        if(!loop[rtr] && !loop[rtc]){
            unite(r,c);continue;
        }
        else{
            unite(r, c);
            loop[rt(r)] = true;
        }
    }
    cout << res << endl;
    return 0;
}