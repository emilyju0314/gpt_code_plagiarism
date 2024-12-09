#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#define x first
#define y second

using namespace std;
const int N = 300050;
int n, m, a[N], vm[N], v[N];
bool st[N];

void update(int i, int u)
{
	v[i] = max(v[i], u);
	for(;i <= 300001; i += i & -i) vm[i] = max(vm[i], u);
}
int query(int l, int r)
{
	int x = 0;
	while(l <= r)
	{
		int nxt = r - (r & -r);
		if(nxt < l)
		{
			x = max(x, v[r]);
			--r;
		}
		else
		{
			x = max(x, vm[r]);
			r = nxt;
		}
	}
	return x;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		int l = max(a + 1 - m, 1), r = min(a + 1 + m, 300001);
//		printf("a = %d, (l, r) = (%d, %d), q = %d \n", a, l, r, query(l, r));
		update(a + 1, query(l, r) + 1);
	}
	cout << query(1, 300001) << endl;
	return 0;
}
