#include<iostream>
using namespace std;
int main()
{
	int n, i, j, pre = 0;
	long long num = 1;
	char a[55] = { 0 };
	cin >> n;
	for (i = 0; i<n; i++)
		cin >> a[i];
	if (a[0] == a[1]) { num = 6; i = 2; pre = 0; }
	else { num = 3; i = 1; pre = 1; }
	for (i; i<n; i++)
	{
		if (i<n-1&&a[i] == a[i + 1])
		{
			if (pre == 0)
			{
				num *= 3;
				num %= 1000000007;
				pre = 0;
			}
			else
			{
				num *= 2;
				num %= 1000000007;
				pre = 0;
			}
			i++;
		}
		else
		{
			if (pre == 0)pre = 1;
			else
			{
				num *= 2;
				num %= 1000000007;
				pre = 1;
			}
		}
	}
	cout << num << endl;
	return 0;
}