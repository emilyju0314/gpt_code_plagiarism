#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int,int> pint;

#define DE 1
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define ALL(s) (s).begin(),(s).end()
#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define EACH(i,s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define COUT(x) cout<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl

template<class T1, class T2> ostream& operator<<(ostream &s, pair<T1,T2> P){return s<<'<'<<P.first<<", "<<P.second<<'>';}
template<class T> ostream& operator<<(ostream &s, vector<T> P) {s<<"{ ";for(int i=0;i<P.size();++i){if(i>0)s<<", ";s<<P[i];}return s<<" }"<<endl;}
template<class T1, class T2> ostream& operator<<(ostream &s, map<T1,T2> P) {s<<"{ ";for(__typeof__(P.begin()) it=P.begin();it!=P.end();++it){if(it!=P.begin())s<<", ";s<<'<'<<it->first<<"->"<<it->second<<'>';}return s<<" }"<<endl;}



typedef double DD;
const DD INF = 1LL<<29;
const DD EPS = 1e-7;
const DD g = 9.8;

struct Para {
	DD f, s, t;
    Para(DD f_ = 0.0, DD s_ = 0.0, DD t_ = 0.0) : f(f_), s(s_), t(t_) {}
};
ostream& operator<<(ostream &s, const Para &p) {
    return s << '<' << p.f << " ; " << p.s << " : " << p.t << '>' << endl;
}
bool operator < (Para p, Para q) {
    return (p.s < q.s);
}
bool operator > (Para p, Para q) {
    return (p.s > q.s);
}

Para makepara(DD vx, DD vy) {
    DD f = -g/2/vx/vx;
    DD s = vy/vx;
    DD t = 0.0;
    return Para(f, s, t);
}

Para envelope(Para p1, Para p2) {
    DD a = p1.f, b = p1.s, c = p1.t;
    DD p = p2.f, q = p2.s, r = p2.t;
    DD f = p*a/(p+a);
    DD s = (p*b+q*a)/(p+a);
    DD t = r+c-(q-b)*(q-b)/4/(p+a);
    return Para(f, s, t);
}

int N;
DD X, Y;
vector<Para> engine;
vector<Para> upline;
vector<pair<DD,DD> > divid;

int main() {
    while (cin >> N) {
        if (N == 0) break;
        
        engine.clear(); upline.clear(); divid.clear();
        for (int i = 0; i < N; ++i) {
            DD vx, vy; cin >> vx >> vy;
            Para p = makepara(vx, vy);
            engine.PB(p);
        }
        cin >> X >> Y;
        
        //COUT(engine);
        sort(ALL(engine), greater<Para>());
        //COUT(engine);
        
        bool isdown = false, isup = false;
        for (int i = 0; i < N; ++i) {
            Para p = engine[i];
            DD h = p.f*X*X + p.s*X + p.t;
            if (Y - h > -EPS) isdown = true;
        }
        
        Para now = engine[0];
        upline.PB(now); divid.PB(MP(0.0, INF));
        for (int i = 1; i < N; ++i) {
            Para p = engine[i];
            DD se = (p.s - now.s)/2/now.f;
            now = envelope(now, p);
            
            upline.PB(now);
            divid[i-1].SE = se;
            divid.PB(MP(se, INF));
        }
        
        //COUT(upline);
        //COUT(divid);
        
        for (int i = 0; i < N; ++i) {
            if (divid[i].FI - EPS < X && X < divid[i].SE + EPS) {
                Para p = upline[i];
                DD h = p.f*X*X + p.s*X + p.t;
                
                //cout << i << " : " << h << endl;
                
                if (h - Y > -EPS) isup = true;
            }
        }
        
        //COUT(isdown); COUT(isup);
         
        if (isdown && isup) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
