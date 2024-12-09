#include <iostream>
#include <cstdio>
using namespace std;
 
typedef long long ll;
ll k, c1, c2;
string s;
int main()
{
	ll i;
	cin >> s >> k;
	if (k % 2) {
		for (i = 1; i < s.size(); i++) {
			if (s[i] == s[i - 1]) c1++, i++;
		}
		if (i == s.size() && s[s.size() - 1] == s[0]) c1++, i = 2;
		else i = 1;
	} else {
		i = 1;
	}
	s += s;
	for (; i < s.size(); i++) {
		if (s[i] == s[i - 1]) c2++, i++;
	}
	c2 *= k / 2;
	if (i == s.size() && s[s.size() - 1] == s[0]) c2 += k / 2 - 1;
	cout << c1 + c2 << endl;
    return 0;
}