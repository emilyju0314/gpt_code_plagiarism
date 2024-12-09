#include<queue>
#include<cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,T,talk[1000],call[1000],wait[1000];

bool solve(int p){
	priority_queue<int> pq;
	rep(i,p) pq.push(0);

	int n_cus=0;
	bool cus[1000]={};
	while(!pq.empty()){
		int t=-pq.top(); pq.pop();

		int i,next=T+1;
		for(i=0;i<n;i++) if(!cus[i]) {
			int total=call[i]+wait[i];
			if(t%total<=call[i]) break;
			else next=min(next,t+total-t%total);
		}
		if(i<n){
			n_cus++;
			cus[i]=true;

			if(t+talk[i]<=T) pq.push(-(t+talk[i]));
			else return false;

			if(n_cus==n) return true;
		}
		else{
			if(next<=T) pq.push(-next);
			else return false;
		}
	}

	return false;
}

int main(){
	for(;scanf("%d%d",&n,&T),n;){
		rep(i,n) scanf("%d%d%d",talk+i,call+i,wait+i);

		int p;
		for(p=1;!solve(p);p++);

		printf("%d\n",p);
	}

	return 0;
}