#include <bits/stdc++.h>
using namespace std;

int N,M,x,y,arr[200010],cnt[200010],sum[200010],total; 

void CreateArray(){
	for(int i=1; i<=N; i++){
		sum[arr[i]]++;
	}
	for(int i=1; i<=N; i++){
		for(int j=i; j>i-min(i,sum[i]); j--)cnt[j]++;
	}
	for(int i=1; i<=N; i++){
		if(cnt[i]==0)total++;
	}
}

void ChangeIdx(){
	cin>>x>>y;
	if(arr[x]>=sum[arr[x]]){
		cnt[arr[x]-sum[arr[x]]+1]--; 
		if(cnt[arr[x]-sum[arr[x]]+1]==0)total++;
	}
	sum[arr[x]]--;
	if(y>sum[y]){
		cnt[y-sum[y]]++;
		if(cnt[y-sum[y]]==1)total--;
	}
	sum[y]++;
	arr[x]=y;
	cout<<total<<'\n';
}

int main(){
	cin>>N>>M;
	for(int i=1; i<=N; i++)cin>>arr[i];
	CreateArray();
	for(int i=0; i<M; i++)ChangeIdx();
}