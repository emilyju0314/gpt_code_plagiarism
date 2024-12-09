#include<bits/stdc++.h>
using namespace std;
double EPS=1e-9;
struct L{
	double a,b,c;
	L(double A,double B,double C){
		a=A;
		b=B;
		c=C;
	}
	L(){}
};
struct P{
	double x,y;
	P(double X,double Y){
		x=X;
		y=Y;
	}
	P(){}
};
inline bool operator < (const P &a,const P &b){
	if(a.x!=b.x){
		return a.x<b.x;
	}else return a.y<b.y;
}
P inter(L s,L t){
	double det=s.a*t.b-s.b*t.a;
	if(abs(det)<EPS){
		return P(1000000009,1000000009);
	}
	return P((t.b*s.c-s.b*t.c)/det,(t.c*s.a-s.c*t.a)/det);
}
bool eq(P a, P b){
	return abs(a.x-b.x)<EPS&&abs(a.y-b.y)<EPS;
}
double dot(P a,P b){
	return a.x*b.x+a.y*b.y;
}
double cross(P a,P b){
	return a.x*b.y-a.y*b.x;
}
double norm(P a){
	return a.x*a.x+a.y*a.y;
}
int ccw(P a,P b,P c){
	b.x-=a.x;
	b.y-=a.y;
	c.x-=a.x;
	c.y-=a.y;
	if(cross(b,c)>0)return 1;
	if(cross(b,c)<0)return -1;
	if(dot(b,c)<0)return 2;
	if(norm(b)<norm(c))return -2;
	return 0;
}
vector<P> convex_hull(vector<P> ps){
	int n=ps.size();
	int k=0;
	std::sort(ps.begin(),ps.end());
	
	vector<P> ch(2*n);
	for(int i=0;i<n;ch[k++]=ps[i++]){
		while(k>=2&&ccw(ch[k-2],ch[k-1],ps[i])<=0)--k;
	}
	
	for(int i=n-2,t=k+1;i>=0;ch[k++]=ps[i--]){
		while(k>=t&&ccw(ch[k-2],ch[k-1],ps[i])<=0)--k;
	}
	ch.resize(k-1);
	return ch;
}
 
char str[51][51];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	double mA1,mA2,mB1,mB2,mX;
	scanf("%lf%lf%lf%lf%lf",&mA1,&mA2,&mB1,&mB2,&mX);
	for(int i=0;i<a;i++){
		scanf("%s",str[i]);
	}
	double tx=0,ux=0,ty=0,uy=0;
	double vx=0,vy=0;
	double wa=0,wb=0,wc=0;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(str[i][j]=='A'){
				wa+=1;
				tx+=0.5+i;
				ty+=0.5+j;
			}else if(str[i][j]=='B'){
				wb+=1;
				ux+=0.5+i;
				uy+=0.5+j;
			}else if(str[i][j]=='X'){
				wc+=1;
				vx+=0.5+i;
				vy+=0.5+j;
			}
		}
	}
	wc*=mX;
	vx*=mX;
	vy*=mX;
	double ret=0;
	double div=(mA2-mA1)*(mB2-mB1);
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(str[i][j]=='.')continue;
			double xl=i;
			double xh=i+1;
			double yl=j;
			double yh=j+1;
			vector<L> lines;
			lines.push_back(L(1,0,mA1));
			lines.push_back(L(1,0,mA2));
			lines.push_back(L(0,1,mB1));
			lines.push_back(L(0,1,mB2));
			lines.push_back(L(tx-wa*xl,ux-wb*xl,-vx+wc*xl));
			lines.push_back(L(tx-wa*xh,ux-wb*xh,-vx+wc*xh));
			lines.push_back(L(ty-wa*yl,uy-wb*yl,-vy+wc*yl));
			lines.push_back(L(ty-wa*yh,uy-wb*yh,-vy+wc*yh));
		//	if(i+j==0)for(int k=0;k<8;k++)printf("%f %f %f\n",lines[k].a,lines[k].b,lines[k].c);
			vector<P> cons;
			for(int k=0;k<8;k++){
				for(int l=k+1;l<8;l++){
					P v=inter(lines[k],lines[l]);
					if(abs(v.x-1000000009)>EPS){
						cons.push_back(v);
					}
				}
			}
			vector<P> ser;
			for(int k=0;k<cons.size();k++){
				bool ok=true;
				for(int l=0;l<8;l++){
					if(l%2==0){
						if(cons[k].x*lines[l].a+cons[k].y*lines[l].b+EPS<lines[l].c)ok=false;
					}else{
						if(cons[k].x*lines[l].a+cons[k].y*lines[l].b>EPS+lines[l].c)ok=false;
					}
				}
				if(ok)ser.push_back(cons[k]);
			}
			if(ser.size()>=3){
				vector<P> D=convex_hull(ser);
		//		if(i==2&&j==0)for(int k=0;k<D.size();k++)printf("%f %f\n",D[k].x,D[k].y);
				double S=0;
				for(int k=0;k<D.size();k++){
					S+=cross(D[k],D[(k+1)%D.size()]);
				}
				ret+=S/2;
		//		printf("%d %d: %f\n",i,j,S/2);
			}
		}
	}
	printf("%.12f\n",ret/div);
}