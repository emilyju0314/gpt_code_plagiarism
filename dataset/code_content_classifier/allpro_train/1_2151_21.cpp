#include <iostream>
using namespace std;
int k,s;
int ans;
int main(){
	cin>>k>>s;
	for(int x=0;x<=k;x++)
		for(int y=0;y<=k;y++){
			int z=s-x-y;
			if(z>=0 && z<=k) ans++;
		}
	cout<<ans;
	return 0;
}
