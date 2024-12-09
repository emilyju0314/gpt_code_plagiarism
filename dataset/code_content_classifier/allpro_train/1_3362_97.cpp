#include <iostream>

using namespace std;

int main() {
	int a,b,i;
	int aa,bb;
	int time=0,sa;
	while(1){
		cin >> a;
		if(a==0) break;
		cin >> b;
		for(i=0;i<b;i++){
			cin >> aa >> bb;
			sa=bb-aa;
			time=time+sa;
		}
		if(time>=a){
			cout << "OK" << endl;
		}else if(time<a){
			cout << a-time << endl;
		} 
		
		time=0;
}
	return 0;
}