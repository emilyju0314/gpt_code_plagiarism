#include <iostream>
using namespace std;

int main(){
	int s;
	int sum = 0;
	for(int i = 0; i < 5; i++){
		cin >> s;
		if(s < 40) sum += 40;
		else sum += s;
	}
	cout << sum/5 << endl;
	return 0;
}
