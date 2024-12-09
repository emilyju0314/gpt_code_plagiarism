#include<cstdio>
#include<iostream>
#include<deque>
#include<vector>
#include<list>
using namespace std;
int main()
{
	int T,r;
	cin >> r >> T;
	vector<vector<int> >a(r);//二维

	while (T--)
	{
		int choose;
		int b, c;
		cin >> choose;
		switch (choose)
		{
		case 0:
			cin >> b>>c;
			a[b].push_back(c);
			break;
		case 1:
			cin >> b;
			for (int i = 0; i < a[b].size(); i++)
			{
				cout << a[b][i];
				if (i != a[b].size() - 1)cout << " ";
			}
			cout << endl;
			break;
		case 2:
			int b;
			cin >> b;
			a[b].clear();
		}
	}
}

