#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	int q1,b,c1,c2,q2;
	while(cin >> q1 , q1){
		cin >> b >> c1 >> c2 >> q2;
		int now = q2 * c1;
		while(now>b){
			now -= c1;
			q2--;
		}
		while(q2+(b-now)/c2 < q1 && q2 > 0){
			now -= c1;
			q2--;
		}
		if(q2>0){
			cout << q2 << " " << (b-now)/c2 << endl;
		}else{
			cout << "NA" << endl;
		}
	}
}