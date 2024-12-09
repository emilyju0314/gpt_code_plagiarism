#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <map>
#include <utility>
#include <queue>
using namespace std;
const double EPS = 1e-8;
const double INF = 1e12;
const double PI = acos(-1);
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define X real()
#define Y imag()

typedef complex<double> P;
typedef vector<P> VP;
struct L : array<P, 2>{
    L(const P& a, const P& b){ at(0)=a; at(1)=b; }
    L(){}
};

namespace std{
    bool operator < (const P& a, const P& b){
        return !EQ(a.X,b.X) ? a.X<b.X : a.Y+EPS<b.Y;
    }
    bool operator == (const P& a, const P& b){
        return abs(a-b) < EPS;
    }
}

double dot(P a, P b){
    return (conj(a)*b).X;
}
double cross(P a, P b){
    return (conj(a)*b).Y;
}
int ccw(P a, P b, P c){
    b -= a;
    c -= a;
    if(cross(b,c) > EPS) return +1; //ccw
    if(cross(b,c) < -EPS) return -1; //cw
    if(dot(b,c) < -EPS) return +2; //c-a-b
    if(abs(c)-abs(b) > EPS) return -2; //a-b-c
    return 0; //a-c-b
}

bool intersectLP(const L& l, const P& p){
    return abs(cross(l[1]-p, l[0]-p)) < EPS;
}

bool isParallel(const P &a, const P &b){
    return abs(cross(a,b)) < EPS;
}
bool isParallel(const L &a, const L &b){
    return isParallel(a[1]-a[0], b[1]-b[0]);
}

P crosspointLL(const L &l, const L &m) {
  double A = cross(l[1]-l[0], m[1]-m[0]);
  double B = cross(l[1]-l[0], l[1]-m[0]);
  return m[0] + B/A *(m[1]-m[0]);
}

pair<vector<vector<pair<int, double> > >, VP> arrangementEX(const vector<L> &l, const VP &p){
    vector<VP> cp(l.size());
    VP plist = p;
    for(int i=0; i<(int)l.size(); i++){
        for(int j=i+1; j<(int)l.size(); j++){
            if(!isParallel(l[i], l[j])){
                P cpij = crosspointLL(l[i], l[j]);
                cp[i].push_back(cpij);
                cp[j].push_back(cpij);
                plist.push_back(cpij);
            }
        }
        for(int j=0; j<(int)p.size(); j++){
            if(intersectLP(l[i], p[j])){
                cp[i].push_back(p[j]);
            }
        }
        cp[i].push_back(l[i][0]);
        cp[i].push_back(l[i][1]);
        plist.push_back(l[i][0]);
        plist.push_back(l[i][1]);
        sort(cp[i].begin(), cp[i].end());
        cp[i].erase(unique(cp[i].begin(), cp[i].end()), cp[i].end());
    }
    sort(plist.begin(), plist.end());
    plist.erase(unique(plist.begin(), plist.end()), plist.end());

    int n = plist.size();
    map<P, int> conv;
    for(int i=0; i<n; i++){
        conv[plist[i]] = i;
    }
    vector<vector<pair<int, double> > > adj(n);
    for(int i=0; i<(int)cp.size(); i++){
        for(int j=0; j<(int)cp[i].size()-1; j++){
            int jidx = conv[cp[i][j]];
            int jp1idx = conv[cp[i][j+1]];
            double dist = abs(cp[i][j] -cp[i][j+1]);
            adj[jidx].emplace_back(jp1idx, dist);
            adj[jp1idx].emplace_back(jidx, dist);
        }
    }
    for(int i=0; i<n; i++){
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    return make_pair(adj, plist);
}

int main(){
    int dn=1;
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;

        VP sg(2);
        for(int i=0; i<2; i++){
            double x,y;
            cin >> x >> y;
            sg[i] = P(x, y);
        }
        vector<L> line(2*n);
        for(int i=0; i<n; i++){
            VP p(2);
            for(int j=0; j<2; j++){
                double x,y;
                cin >> x >> y;
                p[j] = P(x, y);
            }
            P ort = (p[1] -p[0]) *P(0, 1);
            line[2*i +0] = L(p[0], p[0]-ort);
            line[2*i +1] = L(p[1], p[1]+ort);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<2; j++){
                if(ccw(line[2*i +0][0], line[2*i +0][1], sg[j]) != -1 &&
                   ccw(line[2*i +1][0], line[2*i +1][1], sg[j]) != -1){
                    line.emplace_back(sg[j], sg[j] +line[2*i +0][1] -line[2*i +0][0]);
                }
            }  
        }

        pair<vector<vector<pair<int, double> > >, VP> ret = arrangementEX(line, sg);
        vector<vector<pair<int, double> > > &adj = ret.first;
        VP &plist = ret.second;
        int sidx = lower_bound(plist.begin(), plist.end(), sg[0]) -plist.begin();
        int gidx = lower_bound(plist.begin(), plist.end(), sg[1]) -plist.begin();        

        priority_queue<pair<double, int> > wait;
        wait.push(make_pair(0, sidx));
        vector<double> mincost(plist.size(), INF);
        mincost[sidx] = 0;
        while(!wait.empty()){
            double dist = -wait.top().first;
            int pos = wait.top().second;
            wait.pop();
            if(dist > mincost[pos] +EPS) continue;
            if(pos == gidx) break;
            for(pair<int, double> &next: adj[pos]){
                double ndist = dist +next.second;
                double npos = next.first;
                if(ndist +EPS < mincost[npos]){
                    wait.push(make_pair(-ndist, npos));
                    mincost[npos] = ndist;
                }
            }
        }

        cout << fixed << setprecision(5);
        cout << "Case " << dn++ << ": ";
        if(mincost[gidx] == INF){
            cout << "Impossible" << endl;
        }else{
            cout << mincost[gidx] << endl;
        }
    }
    return 0;
}
