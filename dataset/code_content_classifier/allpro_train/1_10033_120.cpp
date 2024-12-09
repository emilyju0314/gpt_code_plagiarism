#include<iostream>
using namespace std;

int main(){
	int n;
	long long ca=0;
	long long b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b;
		ca+=b;
		}
		cout<<ca/n<<endl;
		return 0;
	}