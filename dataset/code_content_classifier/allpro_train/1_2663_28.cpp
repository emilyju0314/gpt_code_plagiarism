#include <bits/stdc++.h>
using namespace std;
typedef long long ll;





int main(){
	string S;
	cin >> S;
	int len = S.length();
	vector<int> v(len);
	
	S = S + "X";
	
	for ( int i = 0; i < len; ){
		int i0 = i;
		
		int R = 0, L = 0;
		// RR...RLL...L の連続数を調べる
		while ( S[i] == 'R' ){
			R++;
			i++;
		}
		while ( S[i] == 'L' ){
			L++;
			i++;
		}
		
		// RLの境界に集まる
		v[i0+R-1]   = (R+1)/2 + L/2;
		v[i0+R] = R/2 + (L+1)/2;
	}
	
	for ( auto it : v )
		cout << it << " ";
	cout << endl;
	
	return 0;
}

