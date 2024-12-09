#include<iostream>
#include<cstring>
using namespace std;

int main(){
	static int a[1000][1000];
	int y[1000],x[1000];
	int h,w;
	cin>>h>>w;
	memset(y,0,sizeof(y));
	memset(x,0,sizeof(x));
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				y[i]++;
				x[j]++;
			}
			a[i][j]-=1;
		}
	}
	for(int i=0;i<h;i++){
		cout<<(a[i][0]+y[i]+x[0])%2;
		for(int j=1;j<w;j++){
			cout<<' '<<(a[i][j]+y[i]+x[j])%2;
		}
		cout<<endl;
	}
}