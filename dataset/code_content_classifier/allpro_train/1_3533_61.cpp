#include <bits/stdc++.h>

using namespace std;

int n,m,i,j,cnt[100005];

int main(){
	scanf("%d%d", &n, &m);
	
	for(i = 0; i < m; i++){
		int x,y;
		scanf("%d%d", &x, &y);
		cnt[x]++;
		cnt[y]++;
	}
	
	bool flag = 1;
	
	for(i = 1; i <= n; i++)
	flag &= (cnt[i] % 2 == 0);
	
	if(flag)
	printf("YES\n");
	else
	printf("NO\n");
}
