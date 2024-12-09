#include <iostream>
#include <string.h>

using namespace std;
int memo[11][400];

void recursive(int depth, int sum, bool flag[10])
{
	++memo[depth][sum];
	for(int i = 0; i < 10; ++i)
	{
		if(flag[i])
		{
			continue;
		}
		flag[i] = true;
		recursive(depth + 1, sum + (depth + 1) * i, flag);
		flag[i] = false;
	}
}

void solve()
{	
	bool flag[10];
	memset(flag, 0, sizeof(flag));
	recursive(0, 0, flag);
	int n, s;
	while(cin >> n >> s)
	{
		if(s >= 331)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << memo[n][s] << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}