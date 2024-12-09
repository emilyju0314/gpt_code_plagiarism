#include<iostream>
using namespace std;
int n,m,c,g,a[10000];
int main(){
	while(true){
		cin>>n>>m;c=1;g=0;if(n==0 && m==0)break;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=m;i++){
			int p;cin>>p;c+=p;
			c+=a[c];
			if(c>=n && g==0){g=i;}
		}
		cout<<g<<endl;
	}
	return 0;
}