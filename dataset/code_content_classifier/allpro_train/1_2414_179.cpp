#include <bits/stdc++.h>
using namespace std;

int n,m;
char a[505][505];

void work()
{
	scanf("%d %d\n",&n,&m);
	for (int i=1; i<=n; i++)  scanf("%s\n",a[i]+1);
	printf("%s\n",a[1]+1);
	for (int i=2; i<n; i++)
		{
			putchar('#');
			for (int j=2; j<m; j++)
				putchar((a[i][j]=='#')||(i%2==0)?'#':'.');
			puts(".");
		}
	printf("%s\n\n",a[n]+1);
	printf("%s\n",a[1]+1);
	for (int i=2; i<n; i++)
		{
			putchar('.');
			for (int j=2; j<m; j++)
				putchar((a[i][j]=='#')||(i%2==1)?'#':'.');
			puts("#");
		}
	printf("%s\n",a[n]+1);
}

int main()
{
	work();
	return 0;
}
