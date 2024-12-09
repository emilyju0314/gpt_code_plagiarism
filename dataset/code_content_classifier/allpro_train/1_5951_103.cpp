#include<bits/stdc++.h>
#define mx 505
using namespace std;
int arr[mx][mx];
int main(){
	int n,m,q;
	cin>>n>>m>>q;
	int a[n+1][n+1];
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		arr[a][b]++;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i][j] += arr[i][j-1];
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		int count = 0;
		for(int i=a;i<=b;i++){
			count += (arr[i][b] - arr[i][i-1]);
		}
		cout<<count<<endl;
	}
}
