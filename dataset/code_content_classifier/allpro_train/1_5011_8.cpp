#include<cstdio>
#include<cmath>
#include<complex>
#include<vector>
#include<algorithm>

using namespace std;

const double eps=1e-9;
const double PI=3.14159265358979323846264;

typedef complex<double> Point;
typedef complex<double> Vector;

template<class T> bool eq(T a,T b){
	return abs(a-b)<eps;
}

double normalize(double ang){
	while(ang<0) ang+=PI*2;
	while(ang>PI*2) ang-=PI*2;
	return ang;
}

struct Circle{
	Point center;
	double r;
	vector<double> angles;//intersections
	Circle(){}
	Circle(Point p,double r):center(p),r(r){}
	bool isin(Point p){
		double dis=abs(p-center);
		return r>dis||eq(r,dis);
	}
	bool isin(Circle c){
		double d=abs(c.center-center)+c.r;
		return r>d;
	}
	Point getPoint(double theta){
		return center+(Point(cos(theta),sin(theta))*r);
	}
	Point onePoint(Circle c){
		double dis=abs(c.center-center);
		if(!eq(dis,r+c.r)){
			return Point(NAN,NAN);
		}
		Vector vec=c.center-center;
		return center+vec*(r/(r+c.r));
	}
	void add(Circle c){
		double r2=c.r;
		double d=abs(c.center-center);
		if(r+r2<d) return;
		double theta=acos((r*r+d*d-r2*r2)/(2.0*r*d));
		Vector vec=c.center-center;
		double phi=atan2(vec.imag(),vec.real());
		angles.push_back(normalize(phi+theta));
		angles.push_back(normalize(phi-theta));
	}
	bool haveCommon(Circle c){
		double d=abs(center-c.center);
		return d<r+c.r||eq(d,r+c.r);
	}
};

vector<Circle> C;
vector<Circle> centerArea;
vector<Circle> circles;
int N,R;

void solve(){
	for(int i=0;i<N;i++){
		if(C[i].r>R){
			printf("0.0\n");
			return;
		}
	}
	for(int i=0;i<N;i++){
		if(C[i].r==R){
			bool flg=true;
			for(int j=0;j<N;j++){
				if(i==j) continue;
				if(C[i].isin(C[j])==false) flg=false;
			}
			if(flg){
				printf("%.f\n",PI*2*R);
			}else{
				printf("0.0\n");
			}
			return;
		}
	}
	for(int i=0;i<N;i++){
		centerArea.push_back(Circle(C[i].center,R-C[i].r));
	}
	for(int i=0;i<N;i++){
		bool flg=true;
		for(int j=0;j<N;j++){
			if(i==j) continue;
			if(centerArea[i].isin(centerArea[j])){
				flg=false;
				break;
			}
		}
		if(flg) circles.push_back(centerArea[i]);
	}
	if(circles.size()==1){
		printf("%f\n",PI*2*(circles[0].r+R));
		return;
	}
	int M=circles.size();
	for(int i=0;i<M;i++) for(int j=i+1;j<M;j++){
		Point pt=circles[i].onePoint(circles[j]);
		if(isnan(pt.real())) continue;
		bool flg=true;
		for(int k=0;k<M;k++){
			if(i==k||j==k) continue;
			if(circles[k].isin(pt)==false) flg=false;
		}
		if(flg){
			printf("%f\n",PI*2*R);
		}else{
			printf("0.0\n");
		}
		return;
	}
	for(int i=0;i<M;i++) for(int j=0;j<M;j++){
		if(circles[i].haveCommon(circles[j])==false){
			printf("0.0\n");
			return;
		}
	}
	for(int i=0;i<M;i++) for(int j=0;j<M;j++){
		if(i==j) continue;
		circles[i].add(circles[j]);
	}
	double totalAng=0;
	double ans=0;
	for(int i=0;i<M;i++){
		Circle cur=circles[i];
		sort(cur.angles.begin(),cur.angles.end());
		for(int j=0;j<cur.angles.size();j++){
			double a=cur.angles[j];
			double b;
			if(j+1==cur.angles.size()){
				b=cur.angles[0]+PI*2;
			}else{
				b=cur.angles[j+1];
			}
			double mid=(a+b)/2;
			Point pt=cur.getPoint(mid);
			bool flg=true;
			for(int k=0;k<M;k++){
				if(circles[k].isin(pt)==false) flg=false;
			}
			if(flg){
				double curAng=b-a;
				ans+=(curAng*(R+cur.r));
				totalAng+=curAng;
			}
		}
	}
	if(totalAng==0){
		printf("0.0\n");
	}else{
		ans+=(PI*2-totalAng)*R;
		printf("%f\n",ans);
	}
}

void init(){
	C.clear();
	centerArea.clear();
	circles.clear();
}

int main(){
	while(true){
		scanf("%d%d",&N,&R);
		if(N==0&&R==0) break;
		init();
		for(int i=0;i<N;i++){
			int x,y,r;
			scanf("%d%d%d",&x,&y,&r);
			C.push_back(Circle(Point(x,y),r));
		}
		solve();
	}
	return 0;
}