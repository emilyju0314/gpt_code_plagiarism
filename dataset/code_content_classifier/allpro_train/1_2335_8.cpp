#include<cmath>
#include<queue>
#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-7;
const double INF=1e77;
const double PI=acos(-1);

template<class T>
struct point{
	T x,y;
	point operator+(const point &a)const{ return (point){x+a.x,y+a.y}; }
	point operator-(const point &a)const{ return (point){x-a.x,y-a.y}; }
};

template<class T>
point<T> operator*(T c,const point<T> &a){ return (point<T>){c*a.x,c*a.y}; }

template<class T>
point<double> operator/(const point<T> &a,double c){
	return (point<double>){a.x/c,a.y/c};
}

bool operator==(const point<double> &a,const point<double> &b){
	return abs(a.x-b.x)<EPS && abs(a.y-b.y)<EPS;
}

bool operator!=(const point<double> &a,const point<double> &b){
	return abs(a.x-b.x)>EPS || abs(a.y-b.y)>EPS;
}

template<class T>
struct line{
	point<T> a,b;
};

template<class T>
struct segment{
	point<T> a,b;
	operator line<T>(){ return (line<T>){a,b}; }
};

template<class T>
struct polygon:vector< point<T> >{
	polygon(){}
	polygon(int n):vector< point<T> >(n){}
};

template<class T>
T abs2(const point<T> &a){ return a.x*a.x+a.y*a.y; }

template<class T>
T dot(const point<T> &a,const point<T> &b){ return a.x*b.x+a.y*b.y; }

template<class T>
T cross(const point<T> &a,const point<T> &b){ return a.x*b.y-a.y*b.x; }

template<class T>
point<double> proj(const point<T> &p,const line<T> &L){
	return L.a+dot(p-L.a,L.b-L.a)/abs2(L.b-L.a)*(L.b-L.a);
}

template<class T>
double arg(const point<T> &a,const point<T> &b){
	double ta=atan2(a.y,a.x);
	double tb=atan2(b.y,b.x);
	return tb<ta ? tb-ta+2*PI : tb-ta;
}

enum {CCW=1,CW=-1,ON=0};
int ccw(const point<double> &a,const point<double> &b,const point<double> &c){
	double rdir=cross(b-a,c-a);
	if(rdir> EPS) return CCW;
	if(rdir<-EPS) return CW;
	return ON;
}

template<class T>
point<double> get_intersect(const line<T> &L1,const line<T> &L2){
	double a1=cross(L1.b-L1.a,L2.b-L2.a);
	double a2=cross(L1.b-L1.a,L1.b-L2.a);
	if(abs(a1)<EPS) return L1.a; // L1 == L2
	return L2.a+a2/a1*(L2.b-L2.a);
}

bool intersect(const line<double> &L,const segment<double> &S){
	return cross(L.b-L.a,S.a-L.a)*cross(L.b-L.a,S.b-L.a)<EPS;
}

bool intersect(const segment<double> &S1,const segment<double> &S2){
	if(max(S1.a.x,S1.b.x)+EPS<min(S2.a.x,S2.b.x)
	|| max(S1.a.y,S1.b.y)+EPS<min(S2.a.y,S2.b.y)
	|| max(S2.a.x,S2.b.x)+EPS<min(S1.a.x,S1.b.x)
	|| max(S2.a.y,S2.b.y)+EPS<min(S1.a.y,S1.b.y)) return false;
	return ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b)<=0
		&& ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b)<=0;
}

template<class T>
double dist(const point<T> &a,const point<T> &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int n; // ビルの数
polygon<double> B[100]; // ビル
point<double> Alice,Bomb; // Alice の位置, 爆弾の位置

// a から b が見えるかどうか ( 視線がビルに遮られていないか ) を判定する
// 見えるとき true を返す
// a, b ともに同じビルの内部にあるときに間違って true を返すけど、そのような a, b に対してこの関数を呼び出すことはない
bool is_visible(const point<double> &a,const point<double> &b){
	segment<double> S={a,b};
	rep(i,n) rep(j,B[i].size()) {
		int m=B[i].size();
		segment<double> T={B[i][j],B[i][(j+1)%m]};

		if(!intersect(S,T)) continue;

		point<double> p=get_intersect(line<double>(S),line<double>(T));
		// ビルの角以外でぶつかったとき
		if(p!=T.a && p!=T.b){
			if(p!=a && p!=b) return false;
			else{
				if(p==a && ccw(b,a,T.a)==CW) return false;
				if(p==b && ccw(a,b,T.a)==CW) return false;
			}
		}
		// ビルの角でぶつかったとき
		else{
			point<double> q=(p==b?a:b); // a, b のうちビルの角でない方の点 ( どちらもビルの角でなければ b を優先 )
			int k=(p==T.a?j:(j+1)%m); // G[i][k]==p なる k
			double t1=arg(B[i][(k-1+m)%m]-p,q-p);
			double t2=arg(B[i][(k-1+m)%m]-p,B[i][(k+1)%m]-p);
			if(!(t1<t2+EPS)) return false;
		}
	}

	return true;
}

// tar に爆風が届くかどうかを判定する
// 届かなければ true を返す
// tar はビルの内部にないことが保障されている
bool is_goal(const point<double> &tar){
	point<double> a=Bomb,b=tar;
	if(!is_visible(a,b)) return true;

	segment<double> S={a,b};
	rep(i,n) rep(j,B[i].size()) {
		int m=B[i].size();
		segment<double> T={B[i][j],B[i][(j+1)%m]};
		if(!intersect(S,T)) continue;

		point<double> p=get_intersect(line<double>(S),line<double>(T));
		// p == a はありえないことが保障されている
		if(p!=b) return true;
		else{
			// p!=T.a && p!=T.b のケースは is_visible ですでに検出されている
			if(p==T.a || p==T.b){
				int k=(p==T.a?j:(j+1)%m);
				int c1=ccw(a,b,B[i][(k-1+m)%m]);
				int c2=ccw(a,b,B[i][(k+1)%m]);
				if(c1==ON || c2==ON || c1==c2) return true;
			}
		}
	}

	return false;
}

struct edge{ int v; double cost; };

double solve(){
	// 終点候補 1
	// ビルの頂点集合
	vector< point<double> > P(1,Alice);
	rep(i,n) P.insert(P.end(),B[i].begin(),B[i].end());

	// 終点候補 2
	// L : 爆風とビルの境目の直線の集合
	vector< line<double> > L;
	rep(i,n) rep(j,B[i].size()) if(is_visible(Bomb,B[i][j])) L.push_back((line<double>){Bomb,B[i][j]});
	// 重複している L の直線を削除
	rep(i,L.size()){
		rep(j,i) if(ccw(L[i].b,Bomb,L[j].b)==ON) { L.erase(L.begin()+i); i--; break; }
	}

	// 終点候補 3
	// R : ビルと L との交点で爆風が届かない点の集合
	vector< point<double> > R;
	rep(i,n) rep(j,B[i].size()) rep(k,L.size()) {
		int m=B[i].size();
		segment<double> S={B[i][j],B[i][(j+1)%m]};
		if(intersect(L[k],S)){
			point<double> p=get_intersect(L[k],line<double>(S));
			if(is_goal(p)) R.push_back(p);
		}
	}
	// あるビルの頂点に一致する R の点を削除
	rep(i,R.size()){
		rep(u,P.size()) if(R[i]==P[u]) { R.erase(R.begin()+i); i--; break; }
	}
	// 重複している R の点を削除
	rep(i,R.size()){
		rep(j,i) if(R[i]==R[j]) { R.erase(R.begin()+i); i--; break; }
	}

	// Dijkstra
	double ans=INF;
	vector<double> d(P.size(),INF);
	d[0]=0;
	priority_queue< pair<double,int> > Q;
	Q.push(make_pair(0,0));
	while(!Q.empty()){
		double d_now=-Q.top().first;
		int u=Q.top().second; Q.pop();

		if(ans<d_now) break;
		if(d[u]<d_now) continue;

		if(is_goal(P[u])){
			ans=d[u];
			break;
		}

		// P[u] から L の垂線の足へ移動するケース
		rep(i,L.size()){
			point<double> p=proj(P[u],L[i]);
			if(is_visible(P[u],p) && is_goal(p)) ans=min(ans,d[u]+dist(P[u],p));
		}

		// P[u] から R の点へ移動するケース
		rep(i,R.size()){
			if(is_visible(P[u],R[i])) ans=min(ans,d[u]+dist(P[u],R[i]));
		}

		rep(v,P.size()) if(u!=v) {
			double cost=dist(P[u],P[v]);
			if(d[v]>d[u]+cost && is_visible(P[u],P[v])){
				d[v]=d[u]+cost;
				Q.push(make_pair(-d[v],v));
			}
		}
	}

	return ans;
}

int main(){
	Alice.x=Alice.y=0;
	for(;scanf("%d",&n),n;){
		scanf("%lf%lf",&Bomb.x,&Bomb.y);
		rep(i,n){
			int m; scanf("%d",&m);
			B[i].resize(m);
			rep(j,m) scanf("%lf%lf",&B[i][j].x,&B[i][j].y);
		}
		printf("%.9f\n",solve());
	}
	return 0;
}