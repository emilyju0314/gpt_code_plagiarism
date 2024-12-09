#include<stdio.h>
#include<algorithm>
using namespace std;
int l[31000];
int r[31000];
double x[31000];
double y[31000];
int h[31000];
int s[31000];
int sum[31000];
int hsum[31000];
int main(){
	int a,b,c,d,e;
	while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&e),a){
		for(int i=0;i<b;i++){
			scanf("%d%d",l+i,r+i);
		}
		for(int i=0;i<b;i++)h[i]=0;
		for(int i=0;i<b;i++){
			if(i)s[i]=(l[i]+r[i]-l[i-1]-r[i-1])*c;
			else s[i]=(l[0]+r[0])*c;
		}
		sum[0]=s[0];
		for(int i=1;i<b;i++){
			sum[i]=sum[i-1]+s[i];
		}
		for(int i=0;i<a;i++)scanf("%lf%lf",x+i,y+i);
		e*=2;
		for(int i=0;i<a;i++){
			int L=0;
			int R=b;
			while(L+1<R){
				int M=(L+R)/2;
				double at=(double)l[M-1]+(double)(r[M-1]-l[M-1])/c*x[i];
				if(at>y[i])R=M;
				else L=M;
			}
			h[L]++;
		}
		for(int i=0;i<=b;i++)hsum[i]=0;
		for(int i=0;i<b;i++)hsum[i+1]=hsum[i]+h[i];
		int ret=999999999;
		int now=0;
		for(int i=0;i<b;i++){
			//if(c*d*2-now<e)break;
			int to=upper_bound(sum,sum+b,now+c*d*2-e)-sum;
			ret=min(ret,a-(hsum[to]-hsum[i]));
			now+=s[i];
		}
		printf("%d\n",ret);
	}
}