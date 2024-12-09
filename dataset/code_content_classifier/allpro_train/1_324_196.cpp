#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	int i, j;
	string s, ans;
	map< pair<char, char>, char > list;
	bool f;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			list[make_pair('1'+i, '1'+j)] = 'a'+i*5+j;
	list[make_pair('6', '1')] = 'z';
	list[make_pair('6', '2')] = '.';
	list[make_pair('6', '3')] = '?';
	list[make_pair('6', '4')] = '!';
	list[make_pair('6', '5')] = ' ';

	while (getline(cin, s)) {
		ans = "";
		f = true;
		if (s.size()&1) {
			f = false;
			s = "";
		}
		for (i = 0; i < s.size(); i+=2) {
			if ( !list.count( make_pair(s[i], s[i+1]) ) ) {
				f = false;
				break;
			}
			ans += list[make_pair(s[i], s[i+1])];
		}
		if (f) cout<<ans<<endl;
		else cout<<"NA"<<endl;
	}
	return 0;
}