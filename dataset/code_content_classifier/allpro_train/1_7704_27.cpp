#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 20000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,M;
ll a[300100],_a[300100],b[300100],c[300100];
int main()
{
	scanf("%d",&N);
	rep(i,N)
	{
		scanf("%lld",&a[i]);
		_a[i]=a[i];
	}
	sort(a,a+N);
	sort(_a,_a+N);
	scanf("%d",&M);
	rep(i,M)scanf("%lld",&b[i]);
	rep(i,M)scanf("%lld",&c[i]);
	_a[N]=INF;
	rep(i,M)a[i+1]+=a[i];
	rep(i,M)
	{
		int k = upper_bound(_a,_a+N+1,b[i])-_a;
		ll sum = (k==0)?0ll:a[k-1];
		if(sum>=c[i])printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}