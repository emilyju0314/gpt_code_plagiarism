#include<stdio.h>
#include<math.h>
double na;
double nx,ny;

int main(){
	int d;
	int a;
	na=90;
	nx=0;
	ny=0;
	while(1){
		scanf("%d,%d",&d,&a);
		if(d==0&&a==0)break;
		nx+=(double)d*cos(M_PI*na/180);
		ny+=(double)d*sin(M_PI*na/180);
		na-=a;
	}
	printf("%d\n%d\n",(int)nx,(int)ny);
}
		