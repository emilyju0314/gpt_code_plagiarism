#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef complex<int> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()

int m, res = 0;
VP ps;

bool isParallel(Point a, Point b){
    return a.Y * b.X == a.X * b.Y;
}

void solve(vector<bool> &used, VP &vs){

    if((int)vs.size() == m/2){
        int cnt = 0;
        rep(i,m/2)rep(j,i){
            if(isParallel(vs[i],vs[j])) cnt++;
        }
        res = max(res,cnt);
        return;
    }

    rep(i,m)if(!used[i]){
        used[i] = true;
        rep(j,m)if(!used[j]){
            vs.push_back(ps[i]-ps[j]);
            used[j] = true;
            solve(used,vs);
            vs.pop_back();
            used[j] = false;
        }
        used[i] = false;
        return;
    }
}

int main(void){
    cin>>m;
    ps.resize(m);
    rep(i,m){
        int x,y;
        cin>>x>>y;
        ps[i] = Point(x,y);
    }
    vector<bool> used(m);
    VP vs;
    solve(used,vs);
    cout<<res<<endl;
    return 0;
}