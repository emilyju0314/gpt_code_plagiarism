#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 100005

int N,M;
int table[NUM];
vector<int> PLUS,MINUS;

int main(){

	ll ans = 0;

	scanf("%d %d",&N,&M);

	for(int i = 0; i < N; i++){

		scanf("%d",&table[i]);
		ans += abs(i-table[i]);

		PLUS.push_back(min(i,table[i]));
		MINUS.push_back(max(i,table[i]));
	}

	sort(PLUS.begin(),PLUS.end());
	sort(MINUS.begin(),MINUS.end());

	reverse(PLUS.begin(),PLUS.end());

	for(int i = 0; i < M; i++){

		ans += 2*max(0,PLUS[i]-MINUS[i]);
	}

	printf("%lld\n",ans);

	return 0;
}

