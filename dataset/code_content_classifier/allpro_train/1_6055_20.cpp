#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

using ld = double;
using Point =  complex<ld>;
const ld eps = 1e-9;
const ld pi = acos(-1.0);

bool eq(ld a, ld b) {
	return (abs(a - b) < eps);
}

bool cmp(Point x,Point y){
	if(eq(x.real(),y.real()))return x.imag()<y.imag();
	return x.real()<y.real();
}

bool eqq(Point x,Point y){
	return eq(x.real(),y.real())&&eq(x.imag(),y.imag());
}
//内積
ld dot(Point a, Point b) {
	return real(conj(a)*b);
}
//外積
ld cross(Point a, Point b) {
	return imag(conj(a)*b);
}


//線分
//直線にするなら十分通い２点を端点とすればよい
class Line {
public:
	Point a, b;
};
//点から直線への垂線の足
Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}
//直線と直線の交点
//平行な２直線に対しては使うな！！！！
Point is_ll(Line s, Line t) {
	Point sv = s.b - s.a; Point tv = t.b - t.a;
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}


Line calc(Line p,Line q){
    if(abs(p.a-p.b)>eps){
        if(abs(q.a-q.b)>eps){
            auto ret=is_ll(p,q);
            return {ret,ret};
        }
        else {
            auto ret = 2.0*proj(p,q.a)-q.a;
            return {ret,ret};
        }
    }
    else {
        if(abs(q.a-q.b)>eps){
            auto ret = 2.0*proj(q,p.a)-p.a;
            return {ret,ret};
        }
        else {
            return {p.a,q.a};
        }
    }
}
int read(string &s,int& i){
    int sgn=0;
    if(s[i]=='-'){
        ++i;
        sgn=1;
    }
    int ret=0;
    while('0'<=s[i]&&s[i]<='9'){
        ret=10*ret+(s[i]-'0');
        ++i;
    }
    return sgn?-ret:ret;
}
Line f(string&s ,int& i);
Line f2(string&s ,int& i);

Line f(string&s ,int& i){
    Line p=f2(s,i);
    while(i!=s.size()&&s[i]=='@'){
        ++i;
        Line q=f2(s,i);
        p=calc(p,q);
    }
    return p;
}
Line f2(string& s,int& i){
    if(s[i]=='('){
        ++i;
        auto ret=f(s,i);
        ++i;
        return ret;
    }
    else {
        int x=read(s,i);
        ++i;
        int y=read(s,i);
        auto p=Point(x,y);
        return {p,p};
    }
}


int main(){
    cout<<fixed<<setprecision(12);
    string s;
    while(cin>>s,s!="#"){
        int i=0;
        auto ret=f(s,i);
        cout<<ret.a.real()<<" "<<ret.a.imag()<<endl;
    }
    return 0;
}
