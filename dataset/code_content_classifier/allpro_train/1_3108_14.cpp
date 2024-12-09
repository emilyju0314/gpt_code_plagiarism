#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
using namespace std;

const double EPS = 1e-6;
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
P unit(const P &p){
    return p/abs(p);
}

bool intersectSS(const L& a, const L& b){
    return ( ccw(a[0],a[1],b[0]) *ccw(a[0],a[1],b[1]) <= 0 ) &&
        ( ccw(b[0],b[1],a[0]) *ccw(b[0],b[1],a[1]) <= 0 );
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

int main(){
    while(1){
        int n,m,b;
        cin >> n >> m >> b;
        if(n == 0) break;

        VP poly(n);
        for(int i=0; i<n; i++){
            double vx,vy;
            cin >> vx >> vy;
            poly[i] = P(vx, vy);
        }
        
        vector<double> ts(m+1);
        VP vs(m+1);
        for(int i=0; i<m; i++){
            double vx,vy;
            cin >> ts[i] >> vx >> vy;
            vs[i] = P(vx, vy);
        }
        //指示終了後は停止し続ける
        ts[m] = INF;
        vs[m] = P(0, 0);
        m++;

        vector<double> tg(b), lg(b);
        VP inig(b), vg(b);
        for(int i=0; i<b; i++){
            double xi,vx,vy;
            cin >> tg[i] >> xi >> vx >> vy >> lg[i];
            inig[i] = P(xi, 0);
            vg[i] = P(vx, vy);
        }
        //ここまで入力

        vector<double> ans;
        for(int bullet=0; bullet<b; bullet++){
            P poss(0, 0), posb = inig[bullet];
            for(int move=0; move<m; move++){
                double time = 0;
                if(move!=0) time = ts[move-1];
                //まだ始まってない
                if(tg[bullet] +EPS > ts[move]){
                    poss += (ts[move] -time) *vs[move];
                    continue;
                }
                //区間の途中で弾丸が発射されるとき
                if(tg[bullet] > time +EPS){
                    poss += (tg[bullet] -time) *vs[move];
                    time = tg[bullet];
                }
                
                L bul(posb, posb +lg[bullet]*unit(-vg[bullet]));
                double mintime = INF;
                //多角形の頂点が弾丸に衝突
                for(int i=0; i<n; i++){
                    P p = poss +poly[i];
                    L locus;
                    locus[0] = p;
                    locus[1] = p +(ts[move] -time) *(vs[move] -vg[bullet]);
                    if(!isParallel(bul, locus) && intersectSS(bul, locus)){
                        P cp = crosspointLL(bul, locus);
                        double ratio = abs(cp -locus[0]) /abs(locus[1] -locus[0]);
                        mintime = min(mintime, time +ratio *(ts[move] -time));
                    }
                }
                //弾丸の端点が多角形の辺に衝突
                for(int d=0; d<2; d++){
                    L locus;
                    locus[0] = bul[d];
                    locus[1] = bul[d] +(ts[move] -time) *(vg[bullet] -vs[move]);
                    for(int i=0; i<n; i++){
                        L edge(poss +poly[i], poss +poly[(i+1)%n]);
                        if(!isParallel(edge, locus) && intersectSS(edge, locus)){
                            P cp = crosspointLL(edge, locus);
                            double ratio = abs(cp -locus[0]) /abs(locus[1] -locus[0]);
                            mintime = min(mintime, time +ratio *(ts[move] -time));
                        }
                    }
                }
                if(mintime != INF){
                    ans.push_back(mintime);
                    break;
                }

                //位置の更新
                poss += (ts[move] -time) *vs[move];
                posb += (ts[move] -time) *vg[bullet];
            }
        }
        sort(ans.begin(), ans.end());
        cout << fixed << setprecision(5);
        cout << ans.size() << endl;
        for(int i=0; i<(int)ans.size(); i++){
            cout << ans[i] << endl;
        }
    }
    return 0;
}
