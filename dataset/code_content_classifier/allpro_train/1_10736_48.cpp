//#include <bits/stdc++.h>
//#include <stdio.h>
#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<string.h>
#include<cmath>
#include<utility>
#include<functional>
#include<map>
#include<set>
#include<cctype>
#include<fstream>


#define FOR(i, a, b) for( int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for( int i=(a);i>=(b);i--)
#define LFOR(i, a, b) for( long long int i=(a);i<=(b);i++)
#define LRFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 600000000 //2000000000
#define LINF 1000000000000000000 //9000000000000000000 大きいとワ―シャルフロイドでオーバーフローを起こす
#define PI 3.14159265358979
#define MAXI 7500000

using namespace std;
typedef long long int ll;
typedef pair< long long int, long long  int> P;

int dy[5] = { 0,0,1,-1,0 };
int dx[5] = { 1,-1,0,0,0 };


int main(void) {
	
	while (1) {
		string s;
		int p;
		int hash;
		int count = 0;

		cin >> s;
		if (s == ".") {
			break;
		}
		cin >> p;

		int a, b, c, d;

		d = p % 10;
		p /= 10;
		c = p % 10;
		p /= 10;
		b = p % 10;
		p /= 10;
		a = p % 10;

		stack<char> sta;
		stack<int> num;
		char first, second, op;
		int front, back;

		FOR(i, 0, s.size() - 1) {
			if (s[i] != ']') {
				sta.push(s[i]);
			}
			else {
				second = sta.top();
				sta.pop();
				first = sta.top();
				sta.pop();
				op = sta.top();
				sta.pop();
				sta.pop();

				switch (first) {
				case 'a':
					front = a;
					break;
				case 'b':
					front = b;
					break;
				case 'c':
					front = c;
					break;
				case 'd':
					front = d;
					break;
				case 'e':
					front = num.top();
					num.pop();
					break;
				}
				switch (second) {
				case 'a':
					back = a;
					break;
				case 'b':
					back = b;
					break;
				case 'c':
					back = c;
					break;
				case 'd':
					back = d;
					break;
				case 'e':
					back = num.top();
					num.pop();
					break;
				}
				switch (op) {
				case '+':
					num.push(front | back);
					break;
				case '*':
					num.push(front&back);
					break;
				case '^':
					num.push(front^back);
					break;
				}
				sta.push('e');
			}
		}

		switch (sta.top()) {
		case 'a':
			hash = a;
			break;
		case 'b':
			hash = b;
			break;
		case 'c':
			hash = c;
			break;
		case 'd':
			hash = d;
			break;
		case 'e':
			hash = num.top();
			num.pop();
			break;
		}

		int now;

		FOR(aa, 0, 9) {
			FOR(bb, 0, 9) {
				FOR(cc, 0, 9) {
					FOR(dd, 0, 9) {
						stack<char> st;
						stack<int>nu;
						FOR(i, 0, s.size() - 1) {
							if (s[i] != ']') {
								st.push(s[i]);
							}
							else {
								second = st.top();
								st.pop();
								first = st.top();
								st.pop();
								op = st.top();
								st.pop();
								st.pop();

								switch (first) {
								case 'a':
									front = aa;
									break;
								case 'b':
									front = bb;
									break;
								case 'c':
									front = cc;
									break;
								case 'd':
									front = dd;
									break;
								case 'e':
									front = nu.top();
									nu.pop();
									break;
								}
								switch (second) {
								case 'a':
									back = aa;
									break;
								case 'b':
									back = bb;
									break;
								case 'c':
									back = cc;
									break;
								case 'd':
									back = dd;
									break;
								case 'e':
									back = nu.top();
									nu.pop();
									break;
								}
								switch (op) {
								case '+':
									nu.push(front | back);
									break;
								case '*':
									nu.push(front&back);
									break;
								case '^':
									nu.push(front^back);
									break;
								}
								st.push('e');
							}
						}

						switch (st.top()) {
						case 'a':
							now = aa;
							break;
						case 'b':
							now = bb;
							break;
						case 'c':
							now = cc;
							break;
						case 'd':
							now = dd;
							break;
						case 'e':
							now = nu.top();
							nu.pop();
							break;
						}

						if (now == hash) {
							count++;
						}
						
						
					}
				}
			}
		}

		cout << hash << " " << count << endl;


	}



	
	

	return 0;
}
