#include<iostream>
#include<algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int u[99],w[99],fl[99],n;
bool rec(int c,int s,int from){
	int prev=-1,f;
	if(c==0){
		for(s=0;s<n&&u[s];s++);
		if(s==n)return 1;
		for(int i=from+1;i<n;i++)if(fl[i]&&w[i]!=prev){
			fl[i]=0; prev=w[i]; f=rec(prev,i+1,i);
			fl[i]=1;
			if(f)return 1;
		}
	}else{
		for(int i=s;i<n;i++)if(!u[i]&&w[i]!=prev&&w[i]<=c){
			u[i]=fl[i]=1; f=rec(c-w[i],i+1,from);
			u[i]=fl[i]=0; prev=w[i];
			if(f)return 1;
		}
	}
	return 0;
}
int main(){
	while(cin>>n,n){
		rep(i,n)cin>>w[i],u[i]=fl[i]=0;
		sort(w,w+n,greater<int>());
		u[0]=1;
		cout<<(n==1||rec(w[0],1,0)?"YES":"NO")<<endl;
	}
	return 0;
}