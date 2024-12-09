#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	string suffix = s;
	smatch m;

	for (auto i = s.cbegin();
		 regex_search(i, s.cend(), m, regex("apple|peach"));
		 i = m[0].second) {
		cout << m.prefix() << (m.str()[0] == 'a' ? "peach" : "apple");
		suffix = m.suffix();
	}
	cout << suffix << endl;
}
