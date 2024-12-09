#include<iostream>
#include<algorithm>
using namespace  std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char line[9];
		cin >> line;
		sort(line, line + 8);
		int mi = 0;
		int ma = 0;
		int ten = 10000000;
		for (int j = 0; j < 8; j++)
		{
			mi += ten * (line[j] - '0');
			ten /= 10;
		}
		ten = 10000000;
		for (int j = 7; j >= 0; j--)
		{
			ma += ten * (line[j] - '0');
			ten /= 10;
		}
		cout << ma - mi << endl;
	}
	return 0;
}