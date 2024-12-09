#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<tuple<int, int, char, long long, string> >vec(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		char c;
		long long d;
		string e;
		cin >> a >> b >> c >> d >> e;
		vec[i] = forward_as_tuple(a,b,c,d,e);
	}
	sort(begin(vec), end(vec));
	for (int i = 0; i < n; i++) {
		int a, b;
		char c;
		long long d;
		string e;
		tie(a, b, c, d, e) = vec[i];
		cout << a << " " << b << " " << c << " " << d << " " << e << endl;
	}
}
