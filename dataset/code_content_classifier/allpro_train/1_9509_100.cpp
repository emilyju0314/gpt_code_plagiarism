#include <iostream>
#include <cstdio>
using namespace std;

string s;
int main() {
	cin >> s;
	if(s.size()==3) swap(s[0], s[2]);
	cout << s;
	return 0;
}