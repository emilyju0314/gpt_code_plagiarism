#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int main(){
	cin>>a>>b>>c>>d;
	for(int i=0;i<=a;i++)
	for(int j=0;j<=b;j++)
	for(int k=0;k<=c;k++)
	if(i*500+j*100+k*50==d)
	e++;
	cout<<e<<endl;
}