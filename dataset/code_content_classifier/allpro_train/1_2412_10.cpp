#include <bits/stdc++.h>

#define MAXN (110)

char str[MAXN];

int main(){
	scanf("%s", str + 1);
	int n = strlen(str + 1), ans = INT_MAX;
	for(int i = 0; i < 26; ++ i){
		str[n + 1] = i + 'a';
		int pre = 0, now = 0;
		for(int j = 1; j <= n + 1; ++ j){
			if(str[j] == i + 'a'){
				now = std::max(now, j - pre - 1);
				pre = j;
			}
		}
		ans = std::min(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}