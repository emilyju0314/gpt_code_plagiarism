#include <string>
#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	s = s.insert(4, " ");
	cout << s << "\n";
	return 0;
}