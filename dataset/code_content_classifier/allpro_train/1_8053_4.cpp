#include<iostream>
using namespace std;
int main(){
	int n,a,b=1000000,c=-1000000;
	long long d=0;
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>a;
	if(a<b){b=a;}
	if(c<a){c=a;}
	d=d+a;
	}
	cout<<b<<" "<<c<<" "<<d<<endl;
	return 0;
}
