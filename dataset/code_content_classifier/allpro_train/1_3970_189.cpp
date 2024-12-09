#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	int a=0,c=0,i,s;

	while(cin >> str){
		s=str.size();
		for(i=0;i<s;i++){
			if(s==1){
				a=1;
				break;
			}else if(str[i]!=str[s-i-1]){
				a=0;
				break;
			}else{
				a=1;
			}
		}
		if(a){
			c++;
		}
	}
	cout << c << endl;
	return 0;
}