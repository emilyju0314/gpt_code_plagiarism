#include<bits/stdc++.h>
using namespace std;
int ufd[101010];
int Find(int a)
{
	if(a==ufd[a]) return a;
	return ufd[a] = Find(ufd[a]);
}
void Union(int a, int b)
{
	ufd[Find(a)] = Find(b);
}
int main()
{
	int N, M; scanf("%d%d", &N, &M);
	for(int i=1; i<=N; ++i) ufd[i] = i;
	for(int i=0; i<M; ++i)
	{
		int x, y;
		scanf("%d%d%*d", &x, &y);
		Union(x, y);
	}
	int ans = 0;
	for(int i=1; i<=N; ++i)
		if(i==Find(i)) ++ans;
	printf("%d\n", ans);
}