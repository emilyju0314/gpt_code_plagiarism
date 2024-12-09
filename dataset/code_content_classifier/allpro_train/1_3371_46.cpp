#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const char *W[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat","All"};
const char *D[]={"Day","Night","All"};

int week,daynight; // 突然変異する曜日, 時間帯

bool isOK(int w,int h){
	return (week==7 || week==w) && (daynight==2 || (daynight==0)==(6<=h && h<18));
}

// jikan wo t dake susumeru
void go(int &w,int &h,int &m,int t){
	w+=t/1440;
	t%=1440;
	h+=t/60;
	t%=60;
	m+=t;
	if(m>=60) m-=60, h++;
	if(h>=24) h-=24, w++;
	w%=7;
}

int main(){
	int born,n,end,stage;
	double p;
	char str1[8],str2[8];
	while(~scanf("%d%d%d%s%s%lf%d",&born,&n,&end,str1,str2,&p,&stage)&&born!=0){
		rep(i,8) if(strcmp(str1,W[i])==0) { week=i; break; }
		rep(i,3) if(strcmp(str2,D[i])==0) { daynight=i; break; }
		p=1-pow(1-1/p,n);

		double ans=0;
		rep(w0,7) rep(h0,24) rep(m0,60) { // initial condition
			double tmp=0;
			int w=w0,h=h0,m=m0;

			double q=p; // 今のステージで突然変異する確率
			rep(i,stage){
				bool ok1=isOK(w,h);
				go(w,h,m,born);
				bool ok2=isOK(w,h);
				go(w,h,m,end-born);
				if(ok1 && ok2) tmp+=q, q*=1-p;
			}
			ans=max(ans,tmp);
		}

		printf("%.9f\n",ans);
	}

	return 0;
}