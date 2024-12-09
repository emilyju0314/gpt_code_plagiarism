#include <bits/stdc++.h>
using namespace std;

long long dfs(long long i,long long n,bool a,bool b,bool c){
	if(i>n) return 0;
	long long count=0;
	if(a&&b&&c) count++;
	count+=dfs(i*10+3,n,true,b,c);
	count+=dfs(i*10+5,n,a,true,c);
	count+=dfs(i*10+7,n,a,b,true);
	return count;
}
 
int main() {
	long long n;
	cin >> n;
	long long ans=dfs(0,n,0,0,0);
	cout << ans << endl;
}
