#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e9;

int main(){
	int n;
	cin >> n;
	vector<vector<int> > c(n, vector<int>(256, 0));
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j=0; j<(int)s.length(); j++){
			c[i][s[j]]++;
		}
	}
	string ans = "";
	for(int i='a'; i<='z'; i++){
		int num = inf;
		for(int j=0; j<n; j++){
			num = min(num, c[j][i]);
		}
		ans += string(num, (char)i);
	}
	cout << ans << endl;
	return 0;
}
