#include<iostream>
using namespace std;
int main() {
	char b, c[128];
	c['A'] = 'T';
	c['G'] = 'C';
	c['C'] = 'G';
	c['T'] = 'A';
	cin >> b;
	cout << c[b] << endl;
	return 0;
}