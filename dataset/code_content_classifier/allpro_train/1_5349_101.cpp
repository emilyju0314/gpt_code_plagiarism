#include <bits/stdc++.h>
using namespace std;

long long n, m, sum, mx=-9e20, a[1005][3], s[1005];

int main() {
	int i, j, k;
	cin>>n>>m;

	for(i=0; i<n; i++) cin>>a[i][0]>>a[i][1]>>a[i][2];

	for(k=0; k<8; k++) {

        //それぞれのケーキに対して、そのケーキを食べた時の絶対値の合計の変化を見る
		for(i=0; i<n; i++) {
			s[i] = 0;

            //kをbit列に直し、xyzに対応させる。1であれば値をそのままの値を足し込み、0であれば
            //マイナスをかけた値を足し込む。
            //つまり、1のときは正の値の絶対値を考え、0のときは負の値の絶対値を考える。
			for(j=0; j<3; j++) s[i] += (k>>j&1 ? a[i][j] : -a[i][j]);
		}

        //昇順にソートし、答えの候補を計算する。
		sort(s, s+n);
		sum = 0;
		for(i=n-1; i>=n-m; i--) sum += s[i];
		mx = max(mx, sum);
	}

	cout<<mx;
	return 0;
}
