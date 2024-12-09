#include<bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;
set<int> pos[ALPHABET_SIZE];
string s;
int n;
int main(int argc, char const *argv[])
{
	cin >> n;
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; ++i)
	{
		pos[s[i] - 'a'].insert(i);
	}
	int q;
	cin >> q;
	while (q --)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int l;
			char ch;
			cin >> l >> ch;
			l --;
			pos[s[l] - 'a'].erase(l);
			s[l] = ch;
			pos[s[l] - 'a'].insert(l);
		}
		else
		{
			int l, r, ans = 0;
			cin >> l >> r;
			l --;
			r --;
			for (int i = 0; i < 26; ++i)
			{
				auto it = pos[i].lower_bound(l);
				if (it == pos[i].end() || *it > r)
					continue;
				else
					ans ++;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}