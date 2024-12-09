#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int maxn = 2e5 + 50;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll p = 13331;
char s[maxn][10],t[maxn][10];
int rd[maxn];
map<ull,int>id;
vector<int>vec[maxn],h[maxn],ans;
set<int>st;
int tuopu(int n)
{
	queue<int>q;
	for (int i = 1 ; i <= n ; i ++)
	 	if (!rd[i]) q.push(i);
	ans.clear();
	while(!q.empty())
	{
		int k = q.front();
		ans.push_back(k);
		q.pop();
		for (int i = 0 ; i < vec[k].size() ; i ++)
		{
			int x = vec[k][i];
			rd[x] --;
			if (!rd[x]) q.push(x);
		}
	}
	for (int i = 1 ; i <= n ; i ++)
	 	if (rd[i]) return 1;	
	return 0;
}
int main()
{
	int n,m,len;
	int cnt = 0;
	scanf("%d%d%d",&n,&m,&len);
	for (int i = 1 ; i <= n ; i ++)
	{
		scanf("%s",s[i] + 1);
		ull sum = 0;
		for (int j = 1 ; j <= len ; j ++)
	 		sum = sum * p + (ll)s[i][j];
		if (id.find(sum) == id.end()) id[sum] = ++ cnt;	
		h[id[sum]].push_back(i);
	}
	char _ = '_';
	int val = (int)_;
	int fd = 0;
	for (int i = 1 ; i <= m ; i ++)
	{
		scanf("%s",t[i] + 1);
		int pos;
		scanf("%d",&pos);
		int flag = 0;
		st.clear();
		for (int j = 0 ; j < (1 << len) ; j ++)
		{
			ull sum = 0;
			for (int k = 0 ; k < len ; k ++)
			{
				if ((j >> k) & 1) sum = sum * p + t[i][k + 1];
				else sum = sum * p + val;
			}
			if (id.find(sum) != id.end())
			{
				int idx = id[sum];
				for (int k = 0 ; k < h[idx].size() ; k ++)
				{
					int x = h[idx][k];
					if (x == pos) flag = 1;
					st.insert(x);
				}
			}
		}
		if (!flag) fd = 1;
		for (auto j : st)
		{
			if (pos == j) continue;
			vec[pos].push_back(j);
			rd[j] ++;
		}
	}
	if (fd)
	{
		printf("NO\n");
		return 0;
	}
	if (tuopu(n)) printf("NO\n");
	else 
	{
		printf("YES\n");
		for (int i = 0 ; i < ans.size() ; i ++)
		{
			printf("%d ",ans[i]);
		}
	}
}

 						 			  	 	 		 				  	