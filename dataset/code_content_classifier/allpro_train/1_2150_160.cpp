#include<cstdio>
#include<iostream>
using namespace std;
int main(void){
	int i,n,a[100001],flash,flg;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	flash=a[1]; flg=0;
	for(i=1;i<=n;i++){
		if(flash==2){
			flg=1;
			break;
		}
		flash=a[flash];
	}
	if(flg==1) cout<<i<<endl;
	else cout<<-1<<endl;
	return 0;
}