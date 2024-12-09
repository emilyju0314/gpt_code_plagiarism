#include <stdio.h>
int n, m, i, j, k, a, b, ans, c[105], s[105];
int main(){
	scanf("%d", &n);
	for(i=2; i<=n; i++){
		for(m=i, j=2; j<=m; j++){
			while(m%j == 0){
				c[j]++, m /= j;
			}
		}
	}
	for(j=2; j<=n; j++){
		if(++c[j] >= 3) s[++a] = c[j];
		if(c[j] >= 5) b++;
	}
	for(i=1; i<=a; i++){
		if(s[i] >= 75) ans++;
		if(s[i] >= 25) ans += a-1;
		if(s[i] >= 15) ans += b-1;
	}
	ans += b*(b-1)*(b-2)/3/2/1*3;
	ans += b*(b-1)/2 * (a-b);
	printf("%d\n", ans);
	return 0;
}