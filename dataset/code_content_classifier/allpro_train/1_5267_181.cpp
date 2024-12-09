#include <iostream>
#include <queue>

using namespace std;

void solve()
{
	int n, m;
	while(cin >> n >> m, n || m)
	{
		deque<bool> deq(n);
		for(int i = 0; i < n; ++i)
		{
			deq[i] = true;
		}
		int remain = n;
		int pos = 0;
		int count = 0;
		while(remain != 1)
		{
			if(pos >= n)
			{
				pos = 0;
			}
			if(deq[pos])
			{
				++count;
			}
			if(count == m)
			{
				deq[pos] = false;
				count = 0;
				--remain;
			}
			++pos;
		}
		for(int i = 0; i < n; ++i)
		{
			if(deq[i])
			{
				cout << i + 1 << endl;
				break;
			}
		}
	}
}

int main()
{
	solve();
	return(0);
}