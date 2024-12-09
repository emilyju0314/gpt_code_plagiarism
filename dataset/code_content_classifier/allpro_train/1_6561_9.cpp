#include<iostream>
#include<algorithm>
using namespace std;
int A,B,C,K;

int main(){
	ios::sync_with_stdio(0);
	cin>>A>>B>>C>>K;
	cout<<A+B+C+max({A,B,C})*((1<<K)-1)<<'\n';
	return 0;
}