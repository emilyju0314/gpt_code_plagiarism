#include<iostream>
#include<deque>
#include<algorithm>
#include<functional>
#include<string>
#include<unordered_map>
using namespace std;

unordered_map<char, string>U;
string b[26] = {
	"100101",//A
	"10011010",//B
	"0101",//C
	"0001",//D
	"110",//E
	"01001",//F
	"10011011",//G
	"010000",//H
	"0111",//I
	"10011000",//J
	"0110",//K
	"00100",//L
	"10011001",//M
	"10011110",//N
	"00101",//O
	"111",//P
	"10011111",//Q
	"1000",//R
	"00110",//S
	"00111",//T
	"10011100",//U
	"10011101",//V
	"000010",//W
	"10010010",//X
	"10010011",//Y
	"10010000",//Z
};
string k = " .,-'?";
signed main() {
	U[' '] = "101";
	U['\''] = "000000";
	U[','] = "000011";
	U['-'] = "10010001";
	U['.'] = "010001";
	U['?'] = "000001";
	string a;
	while (getline(cin,a)) {
		string d;
		for (char c : a) {
			if (c >= 'A'&&c <= 'Z')d += b[c - 'A'];
			else d += U[c];
		}
		while (d.length() % 5)d += "0";
		string ans;
		for (int i = 0; i < d.length() / 5; i++) {
			string e = d.substr(i * 5, 5);
			reverse(e.begin(), e.end());
			int S = 0;
			for (int j = 0; j < 5; j++) {
				if (e[j] == '1')S += 1 << j;
			}
			if (S <= 25)ans += S + 'A';
			else ans += k[S - 26];
		}
		cout << ans << endl;
	}
}