#include <iostream>
using namespace std;
string a;
int main() {
	cin>>a;
	cout<<(a[0]==a[1] || a[1]==a[2] || a[2]==a[3] ? "Bad" : "Good");
	return 0;
}