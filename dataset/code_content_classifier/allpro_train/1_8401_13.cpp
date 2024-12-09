#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int a[1000][1000];
int main(){
	int h,w;cin>>h>>w;
	rep(i,h)rep(j,w)cin>>a[i][j];
	ll sum=0;
	rep(i,h)rep(j,w){
		sum+=a[i][j]*(i+1)*(j+1)*(ll)(h-i)*(ll)(w-j);
	}
	cout<<sum<<endl;
}
