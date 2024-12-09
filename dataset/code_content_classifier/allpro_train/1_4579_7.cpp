#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

/* 基本要素 */
typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double EPS = 1e-6; // 許容誤差^2
const double INF = 1e9;
#define X real()
#define Y imag()
// #define LE(n,m) ((n) < (m) + EPS)
#define LE(n,m) ((n) - (m) < EPS)
// #define GE(n,m) ((n) + EPS > (m))
#define GE(n,m) (EPS > (m) - (n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 内積　dot(a,b) = |a||b|cosθ
double dot(Point a, Point b) {
  return a.X*b.X + a.Y*b.Y;
}

// 外積　cross(a,b) = |a||b|sinθ
double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

// 点の進行方向
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

double distLP(Point a1, Point a2, Point p) {
  return abs(proj(a1, a2, p) - p);
}

double distLC(Point a1, Point a2, Point c, double r) {
  return max(distLP(a1, a2, c) - r, 0.0);
}

VP crosspointLC(Point a1, Point a2, Point c, double r) {
  VP ps;
  Point ft = proj(a1, a2, c);
  if(!GE(r*r,norm(ft-c))) return ps;
  Point dir = sqrt(max(r*r - norm(ft-c), 0.0)) / abs(a2-a1) * (a2-a1);
  ps.push_back(ft + dir);
  if (!EQ(r*r, norm(ft-c))) ps.push_back(ft - dir);
  return ps;
}

// 2円の共通接線。返される各直線に含まれる頂点は円との接点となる
vector<Line> tangentLines(Point a, double ar, Point b, double br) {
  vector<Line> ls;
  double d = abs(b-a);
  rep (i,2) {
    double sin = (ar - (1-i*2)*br) / d;
    if (!LE(sin*sin, 1)) break;
    double cos = sqrt(max(1 - sin*sin, 0.0));
    rep (j,2) {
      Point n = (b-a) * Point(sin, (1-j*2)*cos) / d;
      ls.push_back(Line(a + ar*n, b + (1-i*2)*br*n));
      if (cos < EPS) break;  // 重複する接線を無視（重複していいならこの行不要）
    }
  }
  return ls;
}

const int N = 16;
int dp[1<<N];
int m[N][N][4];

int main(){
    int n;
    cin >>n;

    vector<Point> c(n);
    vector<int> r(n);
    rep(i,n){
        int x,y;
        cin >>x >>y >>r[i];
        c[i] = Point(x,y);
    }

    rep(j,n)rep(i,j){
        vector<Line> seg = tangentLines(c[j],r[j],c[i],r[i]);
        int S = seg.size();
        assert(S==4);
        rep(k,S){
            Line l = seg[k];
            VP tmp = crosspointLC(l.fi,l.se,c[0],r[0]);

            if(tmp.size()>0){
                Point p = tmp[0];
                Point q = l.fi;
                if(ccw(p,q,l.se)==2) continue;

                int val = (1<<i)|(1<<j);
                rep(x,n)if(x!=i && x!=j){
                    VP ump = crosspointLC(p,q,c[x],r[x]);
                    if(ump.size()>0){
                        // dbg(crosspointLC(p,q,c[x],r[x]).size());

                        Point cc = ump[0];
                        if(ccw(p,q,cc)!=2) val |= (1<<x);
                    }
                }

                assert((val&1) == 1);
                m[i][j][k] = m[j][i][k] = val;
            }
        }
    }

    // rep(i,n)rep(j,n)rep(k,4){
    //     printf(" %d %d %d  -> %d\n", i,j,k,m[i][j][k]);
    // }

    fill(dp,dp+(1<<N),10101);
    dp[1] = 0;
    rep(mask,1<<n){
        rep(i,n)rep(j,n)rep(k,4){
            int nmask = (mask|m[i][j][k]);
            dp[nmask] = min(dp[nmask], dp[mask]+1);
        }
    }

    int ans = dp[(1<<n)-1];
    assert(ans<n);
    cout << ans << endl;
    return 0;
}


