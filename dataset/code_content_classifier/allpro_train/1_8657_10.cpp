#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/





string op[2] = { "|", "&" };

pair<int,int> parse(string& s, int& i, int x)
{
	if (x == 2)
	{
		if (s[i] == '(')
		{
			i++;
			auto ans = parse(s, i, 0);
			i++;
			return ans;
		}
		else
		{
			char c = s[i];
			i++;

			if (c == '1') return { 201010, 0 };
			else if (c == '0') return { 0, 201010 };
			else return { 1, 1 };
		}
	}
	else
	{
		vector<pair<int,int>> history;
		history.push_back(parse(s, i, x + 1));

		int flag = 0;

		while (op[x].find(s[i]) != string::npos)
		{
			switch (s[i])
			{
			case '|': i++; history.push_back(parse(s, i, x + 1)); flag = 1; break;
			case '&': i++; history.push_back(parse(s, i, x + 1)); flag = 2; break;
			}
		}

		if (flag == 0) return history.back();
		
		if (flag == 1) { // or
			int zero = 0;
			int yasui = 0;
			int one = inf;
			fore(p, history) {
				chmin(one, zero + p.second);
				zero += p.first;
			}
			return { zero, one };
		}

		if (flag == 2) { // and
			int zero = inf;
			int yasui = 0;
			int one = 0;
			fore(p, history) {
				chmin(zero, one + p.first);
				one += p.second;
			}
			return { zero, one };
		}
	}
}


string S;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S;
	S = S + "#";

	int i = 0;
	auto ans = parse(S, i, 0);

	printf("%d %d\n", ans.first, ans.second);
}





































/*

string op[2] = { "|", "&" };

int parse(string& s, int& i, int x)
{
	if (x == 2)
	{
		if (s[i] == '(')
		{
			i++;
			int ans = parse(s, i, 0);
			i++;
			return ans;
		}
		else
		{
			int ret = 0;

			if (s[i] == '1') ret = 1;
			i++;

			return ret;
		}
	}
	else
	{
		vector<int> history;
		history.push_back(parse(s, i, x + 1));

		int flag = 0;

		while (op[x].find(s[i]) != string::npos)
		{
			switch (s[i])
			{
			case '|': i++; history.push_back(parse(s, i, x + 1)); flag = 1; break;
			case '&': i++; history.push_back(parse(s, i, x + 1)); flag = 2; break;
			}
		}

		int ans = 0;
		if (flag == 0) ans = history.back();
		else if (flag == 1) {
			ans = 0;
			fore(x, history) ans |= x;
		}
		else if (flag == 2) {
			ans = 1;
			fore(x, history) ans &= x;
		}

		return ans;
	}
}

void test() {
	vector<pair<string, int>> testcase = {
		{"0&1", 0},
		{"1&1", 1},
		{"1&0|1", 1},
		{"1&0|1&0", 0},
		{"1&1&0", 0},
		{"(0|0|0|1)&1&(1&0)", 0}
	};

	fore(p, testcase) {
		int i = 0;
		string s = p.first + "#";
		int actual = parse(s, i, 0);
		int expect = p.second;
		
		if (actual != expect) {
			printf("NG!!! %s = %d : ans %d\n", s.c_str(), actual, expect);
		}
	}
}


//---------------------------------------------------------------------------------------------------
void _main() {
	test();
}


*/
