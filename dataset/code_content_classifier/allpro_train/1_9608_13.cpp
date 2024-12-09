#include <cassert>// c
#include <ctime>
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

#define ALL(c) (c).begin(),(c).end()
#define FOR(i,l,r) for(int i=(int)l;i<(int)r;++i)
#define REP(i,n) FOR(i,0,n)
#define FORr(i,l,r) for(int i=(int)r-1;i>=(int)l;--i)
#define REPr(i,n) FORr(i,0,n)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end())
//debug
#define DUMP(x)  cerr << #x << " = " << (x)
#define LINE()    cerr<< " (L" << __LINE__ << ")"

template<typename T,typename U> T pmod(T x,U M){return (x%M+M)%M;}

typedef long long ll;

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


// must template
typedef long double D;
const D INF = 1e12,EPS = 1e-8;

typedef tuple<D,D,D> P;

int sig(D a,D b=0){return a<b-EPS?-1:a>b+EPS?1:0;}

bool eq(D a,D b){return sig(a-b)==0;}
bool eq(const P& a,const P& b){
	return sig(get<0>(a)-get<0>(b))==0
	&& sig(get<1>(a)-get<1>(b))==0
	&& sig(get<2>(a)-get<2>(b))==0;
}
bool compX (const P& a,const P& b){
	return !eq(get<0>(a),get<0>(b))?sig(get<0>(a),get<0>(b))<0:
		!eq(get<1>(a),get<1>(b))?sig(get<1>(a),get<1>(b))<0:
		sig(get<2>(a),get<2>(b))<0;
}
namespace std{
	bool operator <  (const P& a,const P& b){return compX(a,b);}
  	bool operator == (const P& a,const P& b){return eq(a,b);}
};


D dist(const P& a,const P& b){
	return sqrt(norm(get<0>(a)-get<0>(b))+norm(get<1>(a)-get<1>(b))+norm(get<2>(a)-get<2>(b)));
}

bool comp(const pair<P,P>& a,const pair<P,P>& b){
	if(sig(dist(a.first,a.second),dist(b.first,b.second))!=0)return dist(a.first,a.second)<dist(b.first,b.second);
	return a<b;
}

namespace std{
	bool operator <  (const pair<P,P>& a,const pair<P,P>& b){return comp(a,b);}
};


// 雑評価
bool compY (const P& a,const P& b){
	return !eq(get<1>(a),get<1>(b))?sig(get<1>(a),get<1>(b))<0:
		!eq(get<2>(a),get<2>(b))?sig(get<2>(a),get<2>(b))<0:
		sig(get<0>(a),get<0>(b))<0;
}
pair<P,P> closestPair(vector<P>& ps,int l,int r){
    if(r-l<2)return make_pair(P(-INF,-INF,-INF),P(INF,INF,INF));
    pair<P,P> res=min(closestPair(ps,l,(l+r)/2),closestPair(ps,(l+r)/2,r));

    vector<P> ips;
    FOR(i,l,r){
    	if(abs(get<0>(ps[i]) - get<0>(ps[(l+r)/2]))<=dist(res.first,res.second))ips.push_back(ps[i]);
    }
    sort(ALL(ips),compY);
    REP(i,ips.size())for(int j=i-200;j<i;j++)if(j>=0)
    	if(make_pair(min(ips[i],ips[j]),max(ips[i],ips[j])) < res){
    		res=make_pair(min(ips[i],ips[j]),max(ips[i],ips[j]));
    	}
    return res;
}
pair<P,P> closestPair(vector<P>& ps){return closestPair(ps,0,ps.size());}

int main() {
	while(true){
		int m,n,S,W;cin >> m >> n >> S >> W;if(m+n==0)break;

		vector<int> xsres(m+n),ysres(m+n),zsres(m+n);
		REP(i,m)cin >> xsres[i] >> ysres[i] >> zsres[i];
		int g = S;
		for(int i=m; i<m+n; i++) {
		  xsres[i] = (g/7)    %100 + 1;
		  ysres[i] = (g/700)  %100 + 1;
		  zsres[i] = (g/70000)%100 + 1;
		  if( g%2 == 0 ) { g = (g/2); }
		  else           { g = (g/2) ^ W; }
		}
		vector<P> ps(n+m);
		//単位ベクトルのみ
		REP(i,n+m){
			D d=sqrt((D)xsres[i]*xsres[i]+(D)ysres[i]*ysres[i]+(D)zsres[i]*zsres[i]);
			ps[i]=make_tuple(xsres[i]/d,ysres[i]/d,zsres[i]/d);
		}
		sort(ALL(ps),compX);
		ps.erase(unique(ALL(ps)),ps.end());
		pair<P,P> res=closestPair(ps);
		int r1=-1,r2=-1;
		P rp1,rp2;
		REP(i,m+n){
			D d=sqrt((D)xsres[i]*xsres[i]+(D)ysres[i]*ysres[i]+(D)zsres[i]*zsres[i]);
			P p=make_tuple(xsres[i]/d,ysres[i]/d,zsres[i]/d);
			if(eq(res.first,p))if(r1==-1 || res.first<rp1)r1=i;
			if(eq(res.second,p))if(r2==-1 || res.second<rp2)r2=i;
		}
		if(make_tuple(xsres[r1],ysres[r1],zsres[r1])> make_tuple(xsres[r2],ysres[r2],zsres[r2]))swap(r1,r2);
		cout << xsres[r1]<<" "<<ysres[r1] << " " <<zsres[r1]<<" ";
		cout << xsres[r2]<<" "<<ysres[r2] << " " <<zsres[r2]<<endl;
	}
}