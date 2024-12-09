#include<iostream>
using namespace std;
long long int m,s;
long long int t[55][2];

void check(int n){
	if(m==0)return;
	if(m>=t[n][0]){
		m-=t[n][0],s+=t[n][1];
		return;
	}
	m--;
	if(n==0){
		s++;
		return;
	}
	check(n-1);
	if(m==0)return;
	m--,s++;
	check(n-1);
	if(m==0)return;
	m--;
	return;
}	

int main(){
	int n;
	cin>>n>>m;
	t[0][0]=1,t[0][1]=1;
	for(int i=1;i<=n;i++){
		t[i][0]=t[i-1][0]*2+3;
		t[i][1]=t[i-1][1]*2+1;
	}
	check(n);
	cout<<s<<endl;
	return 0;
}
