#include<cmath>
#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-11;
const double INF=1e77;
const double PI=acos(-1);

struct point{
	double x,y;
	point(double x,double y):x(x),y(y){}
};

double arg(const point &a){
	double t=atan2(a.y,a.x);
	return t<0?t+2*PI:t;
}

struct interval{
	double a,b;
	interval():a(0),b(0){}
	interval(const double &a,const double &b):a(a<b?a:b),b(a<b?b:a){}
	bool operator<(const interval &I)const{ return b+EPS<I.b || abs(b-I.b)<EPS && a+EPS<I.a; }
};

bool cover(const interval &I,double x){
	return I.a-EPS<x && x<I.b+EPS;
}

int solve(int n,const interval *I){
	int res=0;
	double x=-INF;
	rep(i,n) if(x+EPS<I[i].a) res++, x=I[i].b;
	return res;
}

int main(){
	int n; scanf("%d",&n);
	int t[2000],l[2000],b[2000],r[2000];
	rep(i,n) scanf("%d%d%d%d",l+i,b+i,r+i,t+i);

	interval I[2000];
	rep(i,n){
		I[i].a=INF;
		I[i].b=-INF;
		if(l[i]>0 && t[i]>=0 && b[i]<0){ // x ティツサツクテ」ツ?ョテヲツュツ」テ」ツ?ョテゥツδィテ・ツ按?」ツつ津」ツ?セテ」ツ?淌」ツ??
			I[i].a=min(I[i].a,arg(point(l[i],b[i])));
			I[i].a=min(I[i].a,arg(point(r[i],b[i])));
			I[i].b=max(I[i].b,arg(point(l[i],t[i]))+2*PI);
			I[i].b=max(I[i].b,arg(point(r[i],t[i]))+2*PI);
		}
		else{
			I[i].a=min(I[i].a,arg(point(l[i],t[i])));
			I[i].a=min(I[i].a,arg(point(l[i],b[i])));
			I[i].a=min(I[i].a,arg(point(r[i],t[i])));
			I[i].a=min(I[i].a,arg(point(r[i],b[i])));
			I[i].b=max(I[i].b,arg(point(l[i],t[i])));
			I[i].b=max(I[i].b,arg(point(l[i],b[i])));
			I[i].b=max(I[i].b,arg(point(r[i],t[i])));
			I[i].b=max(I[i].b,arg(point(r[i],b[i])));
		}
	}
	sort(I,I+n);

	int ans=n;
	rep(i,n){
		int m=0;
		interval J[2000];
		for(int j=i+1;j<n;j++){
			if(!cover(I[j],I[i].b)
			&& !cover(I[j],I[i].b+2*PI)
			&& !cover(I[j],I[i].b-2*PI)) J[m++]=I[j];
		}
		rep(j,i){
			if(!cover(I[j],I[i].b)
			&& !cover(I[j],I[i].b+2*PI)
			&& !cover(I[j],I[i].b-2*PI)) J[m++]=interval(I[j].a+2*PI,I[j].b+2*PI);
		}
		sort(J,J+m);
		ans=min(ans,solve(m,J)+1);
	}
	printf("%d\n",ans);

	return 0;
}