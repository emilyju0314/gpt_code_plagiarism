#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	vector<long long> av(n);
	for (auto& a : av) {
		cin >> a;
	}

	long long c = 1000;
	for(int i = 1; i < n; ++i)
	{
		if (av[i - 1] < av[i]) {
			c = c / av[i - 1] * av[i] + c % av[i - 1];
		}
	}

	cout << c << endl;

	return 0;
}