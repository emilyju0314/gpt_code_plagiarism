#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <map>
#include <queue>
using namespace std;

const double EPS = 1e-6;
const double INF = 1e12;
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

bool intersectSS(const L& a, const L& b){
    return ( ccw(a[0],a[1],b[0]) *ccw(a[0],a[1],b[1]) <= 0 ) &&
        ( ccw(b[0],b[1],a[0]) *ccw(b[0],b[1],a[1]) <= 0 );
}
bool intersectSP(const L& s, const P &p){
    return abs(cross(s[0]-p, s[1]-p))<EPS  && dot(s[0]-p, s[1]-p)<EPS;
}

P crosspointLL(const L &l, const L &m) {
  double A = cross(l[1]-l[0], m[1]-m[0]);
  double B = cross(l[1]-l[0], l[1]-m[0]);
  return m[0] + B/A *(m[1]-m[0]);
}
bool isParallel(const P &a, const P &b){
    return abs(cross(a,b)) < EPS;
}
bool isParallel(const L &a, const L &b){
    return isParallel(a[1]-a[0], b[1]-b[0]);
}

int in_poly(const P &p, const VP &poly){
    int n = poly.size();
    int ret = -1;
    for(int i=0; i<n; i++){
        P a = poly[i]-p;
        P b = poly[(i+1)%n]-p;
        if(a.Y > b.Y) swap(a,b);
        if(intersectSP(L(a,b), P(0,0))) return 0;
        if(a.Y<=0 && b.Y>0 && cross(a,b)<0) ret = -ret;
    }
    return ret;
}

vector<vector<vector<int> > > make_graph(vector<L>& lines, VP &poly, P s, P g){
    VP plist;
    int ls = lines.size();
    vector<VP> cp(ls);
    for(int i=0; i<ls; i++){
        for(int j=i+1; j<ls; j++){
            if(!isParallel(lines[i], lines[j])){
                P cpij = crosspointLL(lines[i], lines[j]);
                if(in_poly(cpij, poly) == -1) continue;
                cp[i].push_back(cpij);
                cp[j].push_back(cpij);
                plist.push_back(cpij);
            }
        }
        sort(cp[i].begin(), cp[i].end());
        cp[i].erase(unique(cp[i].begin(), cp[i].end()), cp[i].end());
    }
    sort(plist.begin(), plist.end());
    plist.erase(unique(plist.begin(), plist.end()), plist.end());
    for(int i=0; i<(int)plist.size(); i++){
        if(plist[i] == s) swap(plist[i], plist[0]);
        if(plist[i] == g) swap(plist[i], plist[1]);
    }
    
    //make convmap (普通にdoubleをキーにすると事故るので、比較関数は誤差ありを使う)
    map<P, int> conv;
    for(int i=0; i<(int)plist.size(); i++){
        conv[plist[i]] = i;
    }

    P dir8[8] = {P(1,0), P(1,1), P(0,1), P(-1,1), P(-1,0), P(-1,-1), P(0,-1), P(1,-1)};
    int n = plist.size();
    //graph[点][向き] = 到達可能点リスト
    vector<vector<vector<int> > > graph(n, vector<vector<int> >(8));
    for(int i=0; i<ls; i++){
        int d=-1; //cp[i][0] から cp[i][1] に進む方向
        for(int j=0; j<8; j++){
            if(intersectSP(L(0, 1e5*dir8[j]), cp[i][1] -cp[i][0])){
                d = j;
                break;
            }
        }

        for(int j=0; j<(int)cp[i].size()-1; j++){
            if(in_poly((cp[i][j] +cp[i][j+1])/2.0, poly) == -1) continue;
            graph[conv[cp[i][j]]][d].push_back(conv[cp[i][j+1]]);
            graph[conv[cp[i][j+1]]][(d+4)%8].push_back(conv[cp[i][j]]);
        }
    }
    
    //壁伝いの移動
    for(int i=0; i<n; i++){
        for(int j=1; j<8; j+=2){
            //壁にぶつかる
            if(in_poly(plist[i]+(0.1*dir8[j]), poly) != -1) continue;
            //かつ壁づたいに動ける
            if(!graph[i][(j+1)%8].empty()){
                graph[i][j].push_back(graph[i][(j+1)%8][0]);
            }
            if(!graph[i][(j+7)%8].empty()){
                graph[i][j].push_back(graph[i][(j+7)%8][0]);
            }
        }
    }
    return graph;
}

int dijkstra(vector<vector<vector<int> > > &graph){
    struct info{
        int v,d,c;
        info(int v, int d, int c):v(v),d(d),c(c){}
        info(){}
        bool operator<(const info &a) const{
            return c > a.c;
        }
    };
    const int inf = 1e9;

    int n = graph.size();
    priority_queue<info> wait;
    vector<vector<int> > mincost(n, vector<int>(8, inf));
    for(int d=0; d<8; d++){
        wait.push(info(0, d, 1));
        mincost[0][d] = 1;
    }
    int ans = inf;
    while(!wait.empty()){
        int v = wait.top().v;
        int d = wait.top().d;
        int c = wait.top().c;
        wait.pop();
        if(c > mincost[v][d]) continue;
        if(v == 1){
            ans = c;
            break;
        }

        for(int nd=0; nd<8; nd++){
            int nc = (d==nd)? c: c+1;
            for(int i=0; i<(int)graph[v][nd].size(); i++){
                int nv = graph[v][nd][i];
                if(nc < mincost[nv][nd]){
                    mincost[nv][nd] = nc;
                    wait.push(info(nv, nd, nc));
                }
            }
        }
    }
    return ans;
}

int main(){
    while(1){
        int n;
        cin >> n;
        if(n==0) break;

        //get input
        int sx,sy,gx,gy;
        cin >> sx >> sy >> gx >> gy;
        P s(sx, sy), g(gx, gy);
        VP poly(n);
        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            poly[i] = P(x, y);
        }

        vector<L> lines;
        P dir4[4] = {P(0,1), P(1,1), P(1,0), P(1,-1)};
        for(int i=0; i<n; i++){
            for(int d=0; d<4; d++){
                lines.push_back(L(poly[i], poly[i]+dir4[d]));
            }
        }
        for(int d=0; d<4; d++){
            lines.push_back(L(s, s+dir4[d]));
            lines.push_back(L(g, g+dir4[d]));
        }

        vector<vector<vector<int> > > graph = make_graph(lines, poly, s, g);
        cout << dijkstra(graph) << endl;
    }   
    return 0;
}

