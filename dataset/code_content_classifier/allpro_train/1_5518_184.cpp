#include<iostream>
using namespace std;
int main(){
	int a;
	int f=0;
	int s[1000];
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>s[i];
		if(s[i]%2==0){
			if(s[i]%5!=0&&s[i]%3!=0){
				f=1;
			}
		}
	}
	if(f)cout<<"DENIED";
	else cout<<"APPROVED";
	return 0;
}