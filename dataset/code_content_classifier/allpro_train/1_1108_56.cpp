#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    string s;
    cin >> s;
    int l = s.length();
    int ans = 0;
    string ss = "";
	string sss = "";
    for(int i = 0; i < l; i++){
    	sss += s[i];
		if(sss != ss){
			ans++;
			ss = sss;
			sss = "";
		}
	}
    cout << ans<< endl;
    return 0;
}