#include <iostream>
using namespace std;
int g, b;
int main() {
	cin>>g>>g>>b;
	cout<<((g*10+b)%4 ? "NO":"YES");
	return 0;
}