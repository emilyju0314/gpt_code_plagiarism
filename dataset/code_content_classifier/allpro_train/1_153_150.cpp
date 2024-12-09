#include <iostream>
using namespace std;
int main()
{
	int l;
	int m,n;
	int a[12];

	while(true){
		int num = 0;
		cin >> l;

		if(l==0)
			break;

		for(int i=0 ;i<12 ;i++){
			cin >> m >> n;

			num = num+(m - n);
			a[i] = num;
		}
		for(int i=0 ;i<12 ;i++){
			
			if(a[i] >= l){
				cout << i+1 << endl;
				break;
			}
			else if(i==11){
				cout << "NA" << endl;
			}
		}
	}
	return 0;
}