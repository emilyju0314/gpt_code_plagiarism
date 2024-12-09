#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int N = 1005;

int n, i, j;
char tab[N][N];

string tab3[3] = {"..a", "..a", "aa."};
string tab4[4] = {"aacd", "bbcd", "cdaa", "cdbb"};
string tab5[5] = {"aabba", "b..ca", "b..cb", "acc.b", "abbaa"};
string tab6[6] = {"aacd..", "bbcd..", "..aacd", "..bbcd", "cd..aa", "cd..bb"};
string tab7[7] = {"abc....", "abc....", "bca....", "bca....", "a..bbcc", "a..ccbb", ".aabbaa"};

void go(int start) {
	for (int i=0;i<4;i++) for (int j=0;j<4;j++) {
		int k1 = i + start;
		int k2 = j + start;
		while (k1 < n) {
			tab[k1][k2] = tab4[i][j];
			k1 += 4;
			k2 += 4;
		}
	}
}

int main() {
scanf("%d", &n);
if (n <= 2) {
	printf("-1\n");
	return 0;
}
for (i=0;i<n;i++) for(j=0;j<n;j++) tab[i][j] = '.';
if (n == 3) {
	for (i=0;i<n;i++) printf("%s\n", tab3[i].c_str()); 
	return 0;
}
else if (n == 4) {
	for (i=0;i<n;i++) printf("%s\n", tab4[i].c_str()); 
	return 0;
}
else if (n == 5) {
	for (i=0;i<n;i++) printf("%s\n", tab5[i].c_str()); 
	return 0;
}
else if (n == 6) {
	for (i=0;i<n;i++) printf("%s\n", tab6[i].c_str()); 
	return 0;
}
else if (n == 7) {
	for (i=0;i<n;i++) printf("%s\n", tab7[i].c_str()); 
	return 0;
} else if (n % 2 == 0) {
	if (n % 4 == 0) go(0); else {
		for (i=0;i<6;i++) for (j=0;j<6;j++) tab[i][j] = tab6[i][j];
		go(6);		
	}
} else {
	if (n % 4 == 1) {
		for (i=0;i<5;i++) for (j=0;j<5;j++) tab[i][j] = tab5[i][j];
		go(5);
	} else {
		for (i=0;i<7;i++) for (j=0;j<7;j++) tab[i][j] = tab7[i][j];
		go(7);
	}
}
for (i=0;i<n;i++) {
	for (j=0;j<n;j++) printf("%c", tab[i][j]);
	printf("\n");
}
return 0;
}



