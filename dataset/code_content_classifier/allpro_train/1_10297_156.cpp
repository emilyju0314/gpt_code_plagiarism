#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int m,a,b;
bool prime[100001];
vector<int> pp;
int main(void){
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i<=100000;i++){
		if(prime[i]){
			pp.push_back(i);
			for(int j=i*2;j<=100000;j+=i){
				prime[j]=false;
			}
		}
	}
	while(1){
		scanf("%d %d %d",&m,&a,&b);
		if(m+a+b==0)break;
		int rp=0,rq=0;
		for(int i=0;i<pp.size();i++){
			if(pp[i]*pp[i]>m)break;
			for(int j=i;j<pp.size();j++){
				if(pp[i]*pp[j]>m)break;
				if(a*pp[j]>b*pp[i])continue;
				if(rp*rq<pp[i]*pp[j]){
					rp=pp[i];
					rq=pp[j];
				}
			}
		}
		printf("%d %d\n",rp,rq);
	}
	return 0;
}