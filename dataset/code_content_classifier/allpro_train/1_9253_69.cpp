#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int n,m,v,ans;
	while(1){
		vector<int>  b ;
		ans=0;
		cin >> n >> m ;
		if( (n==0) && (m==0) ){
			return 0;
		}
		for(int i=0;i<n;i++){
			cin >> v;
			ans += v;
			b.push_back(v);
		}
		sort(b.begin(),b.end());
		reverse(b.begin(),b.end());
		for(int i=m-1;i<n;i+=m){
			ans -= b[i];
		}
		cout << ans << "\n";
	}
}