#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	int i,j,n,k;
	string s;
	cin >> n >> k >> s;
	vector<int> v;
	if(s[0]=='0') v.push_back(0);
	for(i=1;i<n;i++){
		if(s[i]=='0' && s[i-1]=='1') v.push_back(i);
	}
	if(v.size()<=k){
		cout << n << endl;
		return 0;
	}
	int ans = 0;
	for(i=0;i + k - 1<v.size();i++){
		int l = v[i],r = v[i + k - 1],cnt = 0;
		for(j=l - 1;j>=0;j--){
			if(s[j]=='0') break;
			cnt++;
		}
		while(r<n - 1 && s[r + 1]=='0') r++;
		for(j=r+1;j<n;j++){
			if(s[j]=='0') break;
			cnt++;
		}
		ans = max(ans,r - l + cnt + 1);
	}
	cout << ans << endl;
}