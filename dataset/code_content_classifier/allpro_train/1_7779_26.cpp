#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
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
#define INF 2000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<eps)
ll dp[105][105];
ll top[105];
ll bottom[105];
ll rec(int a,int b)//[a,b]
{
	if(dp[a][b]!=-1)return dp[a][b];
	if(a==b)return 0;
	ll res=INF;
	for(int i=a;i<b;i++)
	{
		res=min(res,rec(a,i)+rec(i+1,b)+top[a]*bottom[i]*top[i+1]*bottom[b]);
	}
	return dp[a][b]=res;
}
int main()
{
	int n;
	cin >> n;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)cin >> top[i] >> bottom[i];
	cout << rec(0,n-1) << endl;
	return 0;
}