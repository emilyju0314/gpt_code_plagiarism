#include <cassert>// c
#include <iostream>// io
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>// container
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <algorithm>// other
#include <complex>
#include <numeric>
#include <functional>
#include <random>
#include <regex>
using namespace std;

typedef long long ll;

#define ALL(c) (begin(c)),(end(c))
#define REP(i,n) FOR(i,0,n)
#define REPr(i,n) FORr(i,0,n)
#define FOR(i,l,r) for(int i=(int)(l);i<(int)(r);++i)
#define FORr(i,l,r) for(int i=(int)(r)-1;i>=(int)(l);--i)
#define EACH(it,o) for(auto it = (o).begin(); it != (o).end(); ++it)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end())
//debug
#define DUMP(x)  cerr << #x << " = " << (x)
#define LINE()    cerr<< " (L" << __LINE__ << ")"

class range {
private:
    struct Iter{
        int v;
        int operator*(){return v;}
        bool operator!=(Iter& itr) {return v < itr.v;}
        void operator++() {++v;}
    };
    Iter i, n;
public:
    range(int n) : i({0}), n({n}) {}
    range(int i, int n) : i({i}), n({n}) {}
    Iter& begin() {return i;}
    Iter& end() {return n;}
};

//output
template<typename T> ostream& operator << (ostream& os, const vector<T>& as){REP(i,as.size()){if(i!=0)os<<" "; os<<as[i];}return os;}
template<typename T> ostream& operator << (ostream& os, const vector<vector<T>>& as){REP(i,as.size()){if(i!=0)os<<endl; os<<as[i];}return os;}
template<typename T> ostream& operator << (ostream& os, const set<T>& ss){for(auto a:ss){if(a!=ss.begin())os<<" "; os<<a;}return os;}
template<typename T1,typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p){os<<p.first<<" "<<p.second;return os;}
template<typename K,typename V> ostream& operator << (ostream& os, const map<K,V>& m){bool isF=true;for(auto& p:m){if(!isF)os<<endl;os<<p;isF=false;}return os;}
template<typename T1> ostream& operator << (ostream& os, const tuple<T1>& t){os << get<0>(t);return os;}
template<typename T1,typename T2> ostream& operator << (ostream& os, const tuple<T1,T2>& t){os << get<0>(t)<<" "<<get<1>(t);return os;}
template<typename T1,typename T2,typename T3> ostream& operator << (ostream& os, const tuple<T1,T2,T3>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4,typename T5> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t)<<" "<<get<5>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5,T6,T7>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t)<<" "<<get<5>(t)<<" "<<get<6>(t);return os;}

//input
char tmp[1000];
#define nextInt(n) scanf("%d",&n)
#define nextLong(n) scanf("%lld",&n) //I64d
#define nextDouble(n) scanf("%lf",&n) 
#define nextChar(n) scanf("%c",&n)
#define nextString(n) scanf("%s",tmp);n=tmp

// values
template<typename T> T INF(){assert(false);};
template<> int INF<int>(){return 1<<28;};
template<> ll INF<ll>(){return 1LL<<58;};
template<> float INF<float>(){return 1e10;};
template<> double INF<double>(){return 1e16;};
template<> long double INF<long double>(){return 1e16;};

template<class T> T EPS(){assert(false);};
template<> int EPS<int>(){return 1;};
template<> ll EPS<ll>(){return 1LL;};
template<> float EPS<float>(){return 1e-8;};
template<> double EPS<double>(){return 1e-8;};
template<> long double EPS<long double>(){return 1e-8;};

template<typename T,typename U> T pmod(T v,U M){return (v%M+M)%M;}


namespace _double_tmpl{
    typedef double D;
    
    static constexpr D Ae=0;
    D A(D a,D b){return a+b;}D Ainv(D a){return -a;}
    D S(D a,D b){return A(a,Ainv(b));}
    
    static constexpr D Me=1;
    D M(D a,D b){return a*b;}D Minv(D a){return 1.0/a;};

    int sig(D a,D b=0){return a<b-EPS<D>()?-1:a>b+EPS<D>()?1:0;}
    template<typename T> bool eq(const T& a,const T& b){return sig(abs(a-b))==0;}

    D pfmod(D v,D MOD=2*M_PI){return fmod(fmod(v,MOD)+MOD,MOD);}
    
    //[0,PI)
    D AbsArg(D a){
        D ret=pfmod(max(a,-a),2*M_PI);return min(ret,2*M_PI-ret);
    }
}
using namespace _double_tmpl;

namespace _P{
    // using namespace _double_tmpl;
    typedef complex<D> P,Vec;
    const P O=P(0,0);
#define X real()
#define Y imag()
    istream& operator >> (istream& is,complex<D>& p){
        D x,y;is >> x >> y;p=P(x,y);return is;
    }
    bool compX (const P& a,const P& b){return !eq(a.X,b.X)?sig(a.X,b.X)<0:sig(a.Y,b.Y)<0;}
    bool compY (const P& a,const P& b){return !eq(a.Y,b.Y)?sig(a.Y,b.Y)<0:sig(a.X,b.X)<0;}

    // a×b
    D cross(const Vec& a,const Vec& b){return imag(conj(a)*b);}
    // a・b
    D dot(const Vec&a,const Vec& b) {return real(conj(a)*b);}

    int ccw(const P& a,P b,P c){
        b -= a; c -= a;
        if (sig(cross(b,c))>0)   return +1;       // counter clockwise
        if (sig(cross(b,c))<0)   return -1;       // clockwise
        if (sig(dot(b,c)) < 0)     return +2;       // c--a--b on line
        if (sig(norm(b),norm(c))<0) return -2;       // a--b--c on line
        return 0;
    }

    // 最近点対
    // O(n logn)
    // verified by AOJLIB
    // http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1093043
    D closestPair(vector<P>& ps,int l,int r){
        if(r-l<2)return INF<D>();
        D res=min(closestPair(ps,l,(l+r)/2),closestPair(ps,(l+r)/2,r));
        
        vector<P> ips;FOR(i,l,r)if(abs(ps[i].X - ps[(l+r)/2].X)<res)ips.push_back(ps[i]);
        sort(ALL(ips),compY);
        
        REP(i,ips.size())for(int j=i-10;j<i;j++)if(j>=0)
            res=min(res,abs(ips[i]-ips[j]));

        return res;
    }
    D closestPair(vector<P>& ps){return closestPair(ps,0,ps.size());}


    // verified by 
    // 事前にs-g
    // O-s → O-gの回転方向に関してソート．
    // (同角度の場合、距離が遠い方が前)
    P s,g;
    bool CompArg(const P& p1,const P&p2){
        if(abs(ccw(O,p1,p2))!=1)return abs(p1)>abs(p2);//sameline
        return ccw(O,p1,p2)==ccw(O,s,g);
    }

    //!!
    //角度ソート
    P dir;//基準方向
    bool Comp(const P& p1,const P&p2){
        if(sig(pfmod(arg(p1)-arg(dir)),pfmod(arg(p2)-arg(dir)))==0)return abs(p1)>abs(p2);
        return sig(pfmod(arg(p1)-arg(dir)),pfmod(arg(p2)-arg(dir)));
    }

}
using namespace _P;

namespace std{
    bool operator < (const P& a,const P& b){return _P::compX(a,b);}
    bool operator == (const P& a,const P& b){return eq(a,b);}
};

namespace _L{
    struct L : public vector<P> {
        P vec() const {return this->at(1)-this->at(0);}
        L(const P &a, const P &b){push_back(a); push_back(b);}
        L(){push_back(P(0,0));push_back(P(0,0));}
    };
    istream& operator >> (istream& is,L& l){P s,t;is >> s >> t;l=L(s,t);return is;}

    bool isIntersectLL(const L &l, const L &m) {
        return sig(cross(l.vec(), m.vec()))!=0 || // non-parallel
        sig(cross(l.vec(), m[0]-l[0])) ==0;   // same line
    }
    bool isIntersectLS(const L &l, const L &s) {
      return sig(cross(l.vec(), s[0]-l[0])*       // s[0] is left of l
             cross(l.vec(), s[1]-l[0]))<=0; // s[1] is right of l
    }
    bool isIntersectLP(const L &l, const P &p) {
        return sig(cross(l[1]-p, l[0]-p))==0;
    }

    // verified by ACAC003 B
    // http://judge.u-aizu.ac.jp/onlinejudge/creview.jsp?rid=899178&cid=ACAC003
    bool isIntersectSS(const L &s, const L &t) {
      return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
             ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
    }
    bool isIntersectSP(const L &s, const P &p) {
      return sig(abs(s[0]-p)+abs(s[1]-p),abs(s[1]-s[0])) <=0; // triangle inequality
    }

    // 直線へ射影した時の点
    // verified by AOJLIB
    // http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092212
    P projection(const L &l, const P &p) {
      D t = dot(p-l[0],l.vec()) / norm(l.vec());
      return l[0] + t * l.vec();
    }
    //対称な点
    // verified by AOJLIB
    // http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092214
    P reflection(const L &l, const P &p) {
      return p + 2.0 * (projection(l, p) - p);
    }
    D distanceLP(const L &l, const P &p) {
      return abs(p - projection(l, p));
    }
    D distanceLL(const L &l, const L &m) {
      return isIntersectLL(l, m) ? 0 : distanceLP(l, m[0]);
    }
    D distanceLS(const L &l, const L &s) {
        if (isIntersectLS(l, s)) return 0;
        return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
    }
    D distanceSP(const L &s, const P &p) {
      const P r = projection(s, p);
      if (isIntersectSP(s, r)) return abs(r - p);
      return min(abs(s[0] - p), abs(s[1] - p));
    }
    D distanceSS(const L &s, const L &t) {
        if (isIntersectSS(s, t)) return 0;
        return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
                 min(distanceSP(t, s[0]), distanceSP(t, s[1])));
    }

    // 交点計算
    // verified by AOJLIB
    // http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092231
    P crosspoint(const L &l, const L &m) {
      D A = cross(l.vec(), m.vec()),B = cross(l.vec(), l[1] - m[0]);
      if (sig(A)==0 && sig(B)==0) return m[0]; // same line
      assert(sig(A)!=0);//err -> 交点を持たない．
      return m[0] + B / A * (m[1] - m[0]);
    }
}
using namespace _L;


class Main{
    public:
    void run(){
        int N;cin >> N;
        vector<L> ls(N);
        REP(i,N){
            cin >> ls[i][0] >> ls[i][1];
            if(ls[i][0].X>ls[i][1].X)swap(ls[i][0],ls[i][1]);
        }
        if(N*2>101*101){
            cout <<0<<endl;return;
        }

        D res=INF<D>();
        sort(ALL(ls),[](L l,L r){
            return l[0].X<r[0].X;
        });
        REP(i,N)for(int j=i+1;j<N;j++){
            if(ls[j][0].X-ls[i][1].X >res)break;
            res=min(res,distanceSS(ls[i],ls[j]));
        }
        cout << res << endl;
    
    }
};

int main(){
    cout <<fixed<<setprecision(20);
    cin.tie(0);
    ios::sync_with_stdio(false);
    Main().run();
    return 0;
}