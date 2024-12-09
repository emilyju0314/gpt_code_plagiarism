#include<bits/stdc++.h>
using namespace std;
long long x,y;
int m=0;
int main(){
	cin>>x>>y;
	while(x<=y){
		x*=2;m++;
	}
	cout<<m<<endl;
}