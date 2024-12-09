#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string ,int>ans;

int main(){
	int a;
	char che;
	string str;
	while(cin>>a>>che>>str ){
		ans[str]++;
	}
	cout<<ans["A"]<<endl;
	cout<<ans["B"]<<endl;
	cout<<ans["AB"]<<endl;
	cout<<ans["O"]<<endl;
	
	
}