#include<bits/stdc++.h>
using namespace std;
const double pi=3.14159265358979;
int main(){
	double a,b,c,h,m,i,j,k;
	cin>>a>>b>>h>>m;
	k=abs(h*30-m*5.5);
	k/=180.0;k*=pi;
	c=a*a+b*b-2*a*b*cos(k);
	c=sqrt(c);
	printf("%.12lf",c);
}