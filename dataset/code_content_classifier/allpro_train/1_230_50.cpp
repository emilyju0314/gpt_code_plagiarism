#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

string o = "keyence";

int main(){
	string s;
	cin >> s;
	bool an = s == o;
	f(i, 0, s.size())f(j, i, s.size())if (s.substr(0, i + 1) + s.substr(j) == o)an = true;
	printf("%s\n", an ? "YES" : "NO");
}