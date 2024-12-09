#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, w;
	while (cin >> n >> w && n != 0 || w != 0)
	{
		int bar[11];
		for (int i = 0; i < 11; i++)
		{
			bar[i] = 0;
		}
		int barNum = 0;
		int maxHeight = 0;
		for (int i = 0; i < n; i++)
		{
			int vn;
			cin >> vn;
			bar[vn / w]++;
			maxHeight = max(maxHeight, bar[vn/w]);
			barNum = max(barNum,vn / w);
		}

		double ans = 0.0;
		for (int i = 0; i <= barNum; i++)
		{
			ans += (double)(bar[i] * (barNum - i)) / (double)(maxHeight * barNum);
		}
		ans += 0.01;
		cout << ans << endl;
	}
	return 0;
}