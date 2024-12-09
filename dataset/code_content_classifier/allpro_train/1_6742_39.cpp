#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;


int popcount32(unsigned int x){
	x = (x>>1 & 0x55555555)+(x & 0x55555555);
	x = (x>>2 & 0x33333333)+(x & 0x33333333);
	x = (x>>4 & 0x0f0f0f0f)+(x & 0x0f0f0f0f);
	x = (x>>8 & 0x00ff00ff)+(x & 0x00ff00ff);
	return (x>>16)+(x & 0x0000ffff);
}

int main(){
	int tanni[20];
	int prelearn[20];
	int n,u;
	while(cin>>n>>u,n|u){
		memset(tanni,0,sizeof(tanni));
		memset(prelearn,0,sizeof(prelearn));
		for(int i=0;i<n;i++){
			int c,k;
			cin>>c>>k;
			tanni[i]=c;
			for(int j=0;j<k;j++){
				int r;
				cin>>r;
				prelearn[i]|=1<<r;
			}
		}
		int ans=n;
		for(int i=0;i<(1<<n);i++){
			int pop=popcount32(i);
			if(ans<=pop)continue;
			int pre=0;
			for(int j=0;j<n;j++){
				pre|=(i>>j&1)*prelearn[j];
			}
			if((i&pre)!=pre)continue;
			int s=0;
			for(int j=0;j<n;j++){
				s+=(i>>j&1)*tanni[j];
			}
			if(u<=s)ans=pop;
		}
		cout<<ans<<endl;
	}
    return 0;
}