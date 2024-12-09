#include<iostream>
using namespace std;

int main(){
	int a, b;
	while(1){
		cin >> a >> b;
		if(a == b && a == 0)
			break;
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++)
				cout << "#";
			cout << endl;
		}
		cout << endl;
	}
}
