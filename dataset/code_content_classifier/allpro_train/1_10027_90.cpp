#include <iostream>
using namespace std;

int main(){
	int n;
	string s[101];
	cin >> n;
	bool flag = true;
	for(int i=1;i<=n;i++) {
		cin >> s[i];
		if(i>1 && s[i][0]!=s[i-1][s[i-1].size()-1]){
			flag = false;	
		}
		for(int j=1;j<i;j++){
			if(s[j]==s[i]){
				flag = false;
			}
		}
	}
	cout << (flag?"Yes":"No") << endl;
	return 0;
}