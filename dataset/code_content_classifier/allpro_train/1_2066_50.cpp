// 2013/06/14 Tazoe

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	while(true){
		unsigned n;
		cin >> n;

		if(n==0)
			break;

		unsigned sum = 0;
		for(int i=0; i<n; i++){
			unsigned p;
			cin >> p;

			sum += p;
		}

		unsigned j[65000];
		for(int i=0; i<n-1; i++){
			cin >> j[i];
		}

		sort(j, j+(n-1));

		unsigned sal_max = n*sum;

		for(int i=n-1; i>=1; i--){
			sum += j[i-1];

			sal_max = max(sal_max, (unsigned)i*sum);
		}

		cout << sal_max << endl;
	}

	return 0;
}