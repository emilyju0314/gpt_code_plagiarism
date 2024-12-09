#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <bitset>
#include <time.h>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <stdio.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repk(i, k, n) for (ll i = (k); i < (n); i++)
#define rrep(i, n) for (ll i = (n); i >= 0; i--)
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define test(x) int x;cin>>x; while(x-->0)
#define debug(x) cout << "[ " << #x  << " : " << x << " ]" << endl;

void fast_io()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif
}
 
void solution()
{
    int i;
  int n,p;
  cin>>n;
  int a[n];
  map<int,int>MAP;
  for( i=0;i<n;i++){
      int x;
      cin>>x;
      a[i]=x;
      MAP[x]=MAP[x]+1;
  }
  p=300000;
  for(auto i:MAP){
      if(i.second==1){
          p=min(p,i.first);
      }
  }
  if(p==300000){
      cout<<"-1"<<endl;
  }

  else{
    for(i=0;i<n;i++){
        if(a[i]==p){
            cout<<i+1<<endl;
            break;
        }
    }
  }
  

}
 
int main()
{
	fast_io();
	
	test(t)
	solution();
	//cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	//cerr << sizeof(dp)*(1e-6) << " megabytes\n";
	return 0;
}



