#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define EPS 1e-9
#define pi 4*atan(1.0)
#define rep(i,n) for(int i=0;i<n;i++)

int m,n;
double v;

int main(){
	while(cin>>m&&m){
		double sum=0,area=0;
		rep(i,m-1){
			cin>>v;
			sum+=v;
			area+=sin(v*pi/180.0);
		}
		area+=sin((360.0-sum)*pi/180.0);
		double area2=0;sum=0;
		cin>>n;
		rep(i,n-1){
			cin>>v;
			sum+=v;
			area2+=sin(v*pi/180.0);
		}
		area2+=sin((360.0-sum)*pi/180.0);
		if(abs(area-area2)<EPS)cout<<0<<endl;
		else cout<<(area>area2?1:2)<<endl;
	}
}