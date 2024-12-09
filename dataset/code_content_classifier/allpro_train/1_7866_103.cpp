// 2014/05/23 Tazoe

#include <iostream>
using namespace std;

int main()
{
	while(true){
		int n;
		cin >> n;

		if(n==0)
			break;

		int i[1000], p[1000], q[1000], r[1000];
		for(int j=0; j<n; j++){
			cin >> i[j] >> p[j] >> q[j] >> r[j];
		}

		int P, Q, R, C;
		cin >> P >> Q >> R >> C;

		bool flg = false;

		for(int j=0; j<n; j++){
			if(p[j]<=P && q[j]<=Q && r[j]<=R && 4*p[j]+9*q[j]+4*r[j]<=C){
				cout << i[j] << endl;
				flg = true;
			}
		}

		if(!flg){
			cout << "NA" << endl;
		}
	}

	return 0;
}