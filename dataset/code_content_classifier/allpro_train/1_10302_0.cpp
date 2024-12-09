#include"bits/stdc++.h"
using namespace std;

//define
#define ALL(a) a.begin(),a.end()
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define debug(x) if(1)cout<<#x<<":"<<x<<endl;
#define DEBUG(x) if(1)cout<<#x<<":"<<x<<endl;
#define ll long long

//typedef
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool equation(const string &s, int &i, const int set);
bool formula(const string &s, int &i, const int set);

int main() {
	string s;
	while (cin >> s, s[0] != '#') {
		s += '#';
		bool isok = true;
		for (int i = 0; i < (1 << ('k' - 'a' + 1)); i++) {
			int num=0;
			isok&=equation(s,num,i);
		}
		string res;
		if (isok) {
			res="YES";
		}
		else {
			res="NO";
		}
		cout << res << endl;
	}
	return 0;
}

bool equation(const string &s, int &i, int set) {
	bool lhs = formula(s, i, set);
	i++;
	bool rhs = formula(s, i, set);
	return (lhs == rhs);
}

bool formula(const string &s, int &i, int set) {
	if (s[i] == '-') {
		i++;
		return !formula(s, i, set);
	}
	if (s[i] == '(') {
		i++;
		bool lhs = formula(s, i, set);
		char op = s[i];
		i++;
		if (op == '-') {
			i++;
		}
		bool rhs = formula(s, i, set);
		i++;
		if (op == '*') {
			return lhs&rhs;
		}
		if (op == '+') {
			return lhs | rhs;
		}
		if (op == '-') {
			if (lhs && !(rhs)) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	char val = s[i];
	i++;
	if (val == 'T') {
		return true;
	}
	if (val == 'F') {
		return false;
	}
	return (set & 1 << (val - 'a'));
}