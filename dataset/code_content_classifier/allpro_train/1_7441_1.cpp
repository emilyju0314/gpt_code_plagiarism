#include<stdio.h>
#include<algorithm>
using namespace std;
int x[11000];
int y[11000];
int X[11000];
int Y[11000];
int ABS(int a){return max(a,-a);}
int dist(int X1,int Y1,int X2,int Y2){
	X1+=200000000;
	X2+=200000000;
	Y1+=200000000;
	Y2+=200000000;
	if(X1%20==0&&X2%20==0&&X1==X2)return ABS(Y1-Y2);
	if(Y1%20==0&&Y2%20==0&&Y1==Y2)return ABS(X1-X2);
	if(X1%20==0&&X2%20==0&&Y1/20==Y2/20)return ABS(X1-X2)+min(Y1%20+Y2%20,40-Y1%20-Y2%20);
	if(Y1%20==0&&Y2%20==0&&X1/20==X2/20)return ABS(Y1-Y2)+min(X1%20+X2%20,40-X1%20-X2%20);
	
	return ABS(X1-X2)+ABS(Y1-Y2);
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d%d",x+i,y+i);
	for(int i=0;i<a;i++){
		x[i]*=2;y[i]*=2;
		X[i]=x[i]+y[i];
		Y[i]=x[i]-y[i];
	}
	std::sort(X,X+a);
	std::sort(Y,Y+a);
	int xx=(X[0]+X[a-1])/2;
	int yy=(Y[0]+Y[a-1])/2;
	int mx=(xx+yy)/2;
	int my=(xx-yy)/2;
	double ret=9999999999999.9;
	for(int i=mx-50;i<=mx+50;i++){
		for(int j=my-50;j<=my+50;j++){
			if(ABS(i)%20&&ABS(j)%20)continue;
			int tmp=0;
			for(int k=0;k<a;k++){
				tmp=max(tmp,dist(i,j,x[k],y[k]));
			}
		//	if(tmp<30)printf("%d %d: %d\n",i,j,tmp);
			ret=min(ret,(double)tmp/2);
		}
	}
	printf("%.12f\n",ret);
}