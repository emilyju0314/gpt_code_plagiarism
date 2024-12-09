#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
const double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1);
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
inline double ABS(double a){return max(a,-a);}
struct Pt {
	double x, y;
	Pt() {}
	Pt(double x, double y) : x(x), y(y) {}
	Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator-() const { return Pt(-x, -y); }
	Pt operator*(const double &k) const { return Pt(x * k, y * k); }
	Pt operator/(const double &k) const { return Pt(x / k, y / k); }
	double ABS() const { return sqrt(x * x + y * y); }
	double abs2() const { return x * x + y * y; }
	double arg() const { return atan2(y, x); }
	double dot(const Pt &a) const { return x * a.x + y * a.y; }
	double det(const Pt &a) const { return x * a.y - y * a.x; }
};
double tri(const Pt &a, const Pt &b, const Pt &c) { return (b - a).det(c - a); }

pair<Pt,Pt> pCC(Pt a, double r, Pt b, double s) {
	double d = (b - a).ABS();
	double x = (d * d + r * r - s * s) / (d * 2);
	Pt e = (b - a) / d, w = e * Pt(0, 1) * sqrt(max(r * r - x * x, 0.0));
	return make_pair(a + e * x - w, a + e * x + w);
}
pair<Pt,Pt> pCL(Pt a, double r, Pt b, Pt c) {
	Pt h = b + (c - b) * (c - b).dot(a - b) / (c - b).abs2(); // perp(b, c, a)
	double d = (h - a).ABS();
	double y = sqrt(max(r * r - d * d, 0.0));
	Pt e = (c - b) / (c - b).ABS();
	return make_pair(h - e * y, h + e * y);
}
double dLP(Pt a, Pt b, Pt c) {
	return ABS(tri(a, b, c)) / (b - a).ABS();
}
int sAP(Pt a,Pt b,Pt c){
	return sig(a.det(c))-sig(b.det(c))-sig(a.det(b));
}
Pt p[32];
int bfs[32][32][32][32];
double L1,L2,L3;
vector<Pt> hb1;
vector<Pt> hb2;
inline void add(Pt a,Pt b,Pt c,Pt d){
	if(dLP(a,b,c)<L2){
		pair<Pt,Pt> tmp=pCL(c,L2,a,b);
		if((hb1[0]-c).det(hb1[1]-c)<-EPS)swap(hb1[0],hb1[1]);
		if(sAP(hb1[0]-c,hb1[1]-c,tmp.first-c)>=0)hb1.push_back(tmp.first);
		if(sAP(hb1[0]-c,hb1[1]-c,tmp.second-c)>=0)hb1.push_back(tmp.second);
	}
	pair<Pt,Pt> tmp2=pCL(a,L2,a,b);
	if((hb1[0]-a).det(hb1[1]-a)<-EPS)swap(hb1[0],hb1[1]);
	if(sAP(hb1[0]-a,hb1[1]-a,tmp2.first-a)>=0)hb1.push_back(tmp2.first);
	if(sAP(hb1[0]-a,hb1[1]-a,tmp2.second-a)>=0)hb1.push_back(tmp2.second);
	if(dLP(a,b,d)<L3){
		pair<Pt,Pt> tmp=pCL(d,L3,a,b);
		if((hb2[0]-d).det(hb2[1]-d)<-EPS)swap(hb2[0],hb2[1]);
		if(sAP(hb2[0]-d,hb2[1]-d,tmp.first-d)>=0)hb2.push_back(tmp.first);
		if(sAP(hb2[0]-d,hb2[1]-d,tmp.second-d)>=0)hb2.push_back(tmp.second);
	}
	tmp2=pCL(b,L3,a,b);
	if((hb2[0]-b).det(hb2[1]-b)<-EPS)swap(hb2[0],hb2[1]);
	if(sAP(hb2[0]-b,hb2[1]-b,tmp2.first-b)>=0)hb2.push_back(tmp2.first);
	if(sAP(hb2[0]-b,hb2[1]-b,tmp2.second-b)>=0)hb2.push_back(tmp2.second);
}
bool debug;
inline int check(Pt a,Pt b,Pt c,Pt d){
	if((b-a).ABS()>L2*2)return 0;
	if((d-c).ABS()>L3*2)return 0;
	hb1.clear();
	hb2.clear();
	pair<Pt,Pt> T1=pCC(a,L2,b,L2);
	pair<Pt,Pt> T2=pCC(c,L3,d,L3);
	if((T1.first-c).ABS()<L3&&(T1.first-d).ABS()<L3)return 1;
	if((T2.first-a).ABS()<L2&&(T2.first-b).ABS()<L2)return 1;
	hb1.push_back(T1.first);
	hb1.push_back(T1.second);
	hb2.push_back(T2.first);
	hb2.push_back(T2.second);
	add(a,c,b,d);
	add(a,d,b,c);
	add(b,c,a,d);
	add(b,d,a,c);
	for(int i=0;i<hb1.size();i++)for(int j=0;j<hb2.size();j++){
		if((hb1[i]-hb2[j]).ABS()<L1){
		//	if(debug)printf("%f %f %f %f\n",hb1[i].x,hb1[i].y,hb2[j].x,hb2[j].y);
			return 1;
		}
	}
	return 0;
}
int main(){
	int a;
	scanf("%d",&a);
	scanf("%lf%lf%lf",&L1,&L2,&L3);
	L1-=1e-6;
	L2-=1e-6;
	L3-=1e-6;
	for(int i=0;i<a;i++){
		double X,Y;
		scanf("%lf%lf",&X,&Y);
		p[i]=Pt(X,Y);
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++)for(int k=0;k<a;k++)for(int l=0;l<a;l++)
			bfs[i][j][k][l]=99999999;
	}
	bfs[0][1][2][3]=0;
	queue<pair<pair<int,int>,pair<int,int> > >Q;
	Q.push(make_pair(make_pair(0,1),make_pair(2,3)));
	while(Q.size()){
		int TL=Q.front().first.first;
		int TR=Q.front().first.second;
		int BL=Q.front().second.first;
		int BR=Q.front().second.second;
		int now=bfs[TL][TR][BL][BR];
		Q.pop();
		if(TL==a-1||TR==a-1||BL==a-1||BR==a-1)break;
	//	printf("%d %d %d %d: %d\n",TL,TR,BL,BR,now);
	//	debug=false;
		for(int i=0;i<a;i++){
			if(TL==i||TR==i||BL==i||BR==i)continue;
			if(bfs[min(i,TR)][max(i,TR)][BL][BR]>9999999){
				if(check(p[i],p[TR],p[BL],p[BR])){
					bfs[min(i,TR)][max(i,TR)][BL][BR]=now+1;
					Q.push(make_pair(make_pair(min(i,TR),max(i,TR)),make_pair(BL,BR)));
				}
			}
			if(bfs[min(i,TL)][max(i,TL)][BL][BR]>9999999){
	//			if(TL==4&&i==5&&BL==2&&BR==3)debug=true;
				if(check(p[TL],p[i],p[BL],p[BR])){
					bfs[min(i,TL)][max(i,TL)][BL][BR]=now+1;
					Q.push(make_pair(make_pair(min(TL,i),max(TL,i)),make_pair(BL,BR)));
				}
			}
	//		debug=false;
			if(bfs[TL][TR][min(i,BR)][max(i,BR)]>9999999){
				if(check(p[TL],p[TR],p[i],p[BR])){
					bfs[TL][TR][min(i,BR)][max(i,BR)]=now+1;
					Q.push(make_pair(make_pair(TL,TR),make_pair(min(i,BR),max(i,BR))));
				}
			}
			if(bfs[TL][TR][min(i,BL)][max(i,BL)]>9999999){
				if(check(p[TL],p[TR],p[BL],p[i])){
					bfs[TL][TR][min(i,BL)][max(i,BL)]=now+1;
					Q.push(make_pair(make_pair(TL,TR),make_pair(min(i,BL),max(i,BL))));
				}
			}
		}
		
	}
	int ret=99999999;
	for(int i=0;i<a;i++)for(int j=0;j<a;j++)for(int k=0;k<a;k++){
		ret=min(ret,bfs[i][j][k][a-1]);
		ret=min(ret,bfs[i][j][a-1][k]);
		ret=min(ret,bfs[i][a-1][j][k]);
		ret=min(ret,bfs[a-1][i][j][k]);
	}
	if(ret>999999)printf("-1\n");
	else printf("%d\n",ret);
}