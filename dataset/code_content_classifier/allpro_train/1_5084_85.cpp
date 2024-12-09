#include<stdio.h>
int main(void)
{
	int n, ans[100000], i, j, a;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		ans[a] = i;
	}

	for (i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}

}