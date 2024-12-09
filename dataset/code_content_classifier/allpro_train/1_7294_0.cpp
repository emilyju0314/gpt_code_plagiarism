#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main()
{
	IOS;
	int q;
	cin >> q;
	int id = 0;
	map<int, queue<int> > m;
	set<int> have;
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			id++;
			have.insert(id);
			int val;
			cin >> val;
			m[val].push(id);
		}
		else if(type == 2)
		{
			int val = *have.begin();
			cout << val << " ";
			have.erase(val);
		}
		else
		{
			int val = -1;
			while(val == -1)
			{
				auto it = m.rbegin();
				if(have.find(it->second.front()) == have.end())
				{
					it->second.pop();
					if(it->second.size() == 0)
						m.erase(it->first);
				}
				else
				{
					val = it->second.front();
					it->second.pop();
					if(it->second.size() == 0)
						m.erase(it->first);
					have.erase(val);
				}
			}
			cout << val << " ";
		}
	}
	return 0;
}