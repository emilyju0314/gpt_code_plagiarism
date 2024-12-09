#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,p;cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>p;if(p!=i)ans++;
	}
	cout<<(ans<3?"YES":"NO")<<endl;
}