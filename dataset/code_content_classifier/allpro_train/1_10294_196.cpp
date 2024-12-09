#include <iostream>
using namespace std;

int main()
{
	int D,L;
	int count = 0;
	cin >> D >> L;
	for (;D - L > -1;) {
		D -= L;
		count++;
	}
	count += D;
	cout << count<<endl;
    return 0;
}