#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> ans;
signed main(){
	int n, a, b;
	scanf("%lld%lld%lld", &n, &a, &b);
	if(n < a+b-1 || n > a*b){
		printf("-1\n");
		return 0;
	}
	
	int x = n-a, cnt = n-a+1;
	for(int i = cnt;i <= n;i++)ans.push_back(i);
	for(int i = 0;i < b-1;i++){
		int d = x/(b-1);
		if(x%(b-1) > i)d++;
		cnt -= d;
		for(int j = cnt;j < cnt+d;j++)ans.push_back(j);
	}
	
	printf("%lld", ans[0]);
	for(int i = 1;i < ans.size();i++)printf(" %lld", ans[i]);
	printf("\n");
	return 0;
}