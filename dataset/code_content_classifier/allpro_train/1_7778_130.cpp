#include <iostream>
#include <stack>
using namespace std;

int main(){
	int n;
	stack<int> s;
	while(cin >> n){
		if(!n){cout << s.top() << endl;s.pop();}
		else s.push(n);
	}
	return 0; 
}