#include<cmath>
#include<cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

int R,r,d;

double f(double t){
	double a=1-(double)R/r;
	double x_dash=-(R-r)*sin(t)-a*d*sin(a*t);
	double y_dash= (R-r)*cos(t)+a*d*cos(a*t);
	return sqrt(x_dash*x_dash+y_dash*y_dash);
}

int main(){
	for(;scanf("%d%d%d",&R,&r,&d),R;){
		int k;
		if(d==0) k=1; // hypotrochoid が縮退して円になっている
		else{
			for(k=1;k*(r-R)%r!=0;k++);
		}
		double T=2*k*PI; // 周期

		double ans=0;
		int n=10000; // 何等分するか
		rep(i,n){
			double t1=T*i/n,t2=T*(i+1)/n;
			ans+=f((t1+t2)/2)*(t2-t1);
		}
		printf("%.9f\n",ans);
	}

	return 0;
}