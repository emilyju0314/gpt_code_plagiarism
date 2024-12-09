#include<iostream>
#include<string>
using namespace std;

int main(){
	
	string abc;
	int m,h;
	
	while (1){
		cin >> abc;
		if (abc=="-") break;
		cin >> m;
		for (int i=0; i<m; i++){
			cin >> h;
			abc = abc.erase(0,h)+abc.substr(0,h);
		}
		cout << abc << endl;
	}
	return 0;
}