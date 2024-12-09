#include <iostream>

using namespace std;

int main()
{
	long a, b, c, k;
	cin >> a >> b >> c >> k;
	while (a >= b)
	{
		k--;
		b *= 2;
	}
	while (b >= c)
	{
		k--;
		c *= 2;
	}
	cout << (k < 0 ? "No" : "Yes") << endl;
	return 0;
}