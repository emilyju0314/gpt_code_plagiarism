#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>
#include <complex>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define EPS 1e-8
#define F first
#define S second

static const double PI=6*asin(0.5);
typedef pair<double,double> P;
typedef complex<double> CP;
typedef long long ll;


int main(){
	double t;
	P a,b,c,d;
	while(cin>>a.F>>a.S>>b.F>>b.S>>c.F>>c.S>>d.F>>d.S){
		bool f=false;
		if((d.F>=a.F)&&c.F<=b.F){
			if((d.S>=a.S)&&c.S<=b.S){
				f=true;
			}
		}
		if(f) cout<<"YES\n";
		else cout<<"NO\n";
		
	}
	return 0;
}