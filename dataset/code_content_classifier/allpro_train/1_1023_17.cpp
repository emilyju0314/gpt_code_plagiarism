#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

pair<int,int> p[100005];

int main(){
  int n,h,x=0;	cin>>n>>h;
  for(int i = 0; i < n; i++){
	cin>>p[i].se>>p[i].fi;
	x = max(x,p[i].se);
  }
  sort(p,p+n);
  int s = 0, c = 0;
  for(int i = n-1; i >= 0; i--){
	if(p[i].fi < x)	break;
	s += p[i].fi;	c++;
	if(s >= h){
		cout<<c;
		return 0;
	}
  }
  cout<<(h-s-1)/x+1+c;
  return 0;
}