#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> p;
int dx[12] = {-1,  0,  1,  2, 2, 2, 1, 0, -1, -2, -2, -2};
int dy[12] = {-2, -2, -2, -1, 0, 1, 2, 2,  2,  1,  0, -1};

void solve()
{
	p pos;
	while(cin >> pos.first >> pos.second, pos.first || pos.second)
	{
		queue<p> states;
		states.push(pos);
		int n;
		cin >> n;
		vector<p> sp(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> sp[i].first >> sp[i].second;
		}
		bool flag = true;
		for(int i = 0; i < n; ++i)
		{
			if(states.size() == 0)
			{
				flag = false;
				break;
			}
			queue<p> next_states;
			while(states.size())
			{
				pos.first = states.front().first;
				pos.second = states.front().second;
				states.pop();
				p np;
				for(int j = 0; j < 12; ++j)
				{
					np.first = pos.first + dx[j];
					np.second = pos.second + dy[j];
					if((0 <= np.first && np.first <= 9 && 0 <= np.second && np.second <= 9) &&
					   (sp[i].first - 1 <= np.first && np.first <= sp[i].first + 1) &&
					   (sp[i].second - 1 <= np.second && np.second <= sp[i].second + 1))
					{
						next_states.push(p(np.first, np.second));
					}
				}
			}
			while(next_states.size())
			{
				states.push(next_states.front());
				next_states.pop();
			}
		}
		if(!flag || states.size() == 0)
		{
			cout << "NA" << endl;
		}
		else
		{
			cout << "OK" << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}