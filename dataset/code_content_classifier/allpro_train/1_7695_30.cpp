#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
priority_queue<int>q;
int n,m,a[1111],b[1111];
void END(){
	cout<<0<<endl;
	exit(0);
}
int main(){
	cin>>n>>m;
	r(i,n)cin>>a[i];
	r(i,m){
		cin>>b[i];
		if(b[i])q.push(b[i]);
	}
	r(i,n){
		queue<int>tmp;
		r(j,a[i]){
			if(q.empty())END();
			if(q.top()!=1)tmp.push(q.top()-1);
			q.pop();
		}
		while(!tmp.empty())q.push(tmp.front()) , tmp.pop();
	}
	if(!q.empty())END();
	cout<<1<<endl;
}
