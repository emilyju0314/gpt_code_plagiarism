#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	while (true) {
		int N,M;cin>>N>>M;
		if(!N)break;
		int ans=-1;

		//fst: time    snd: dif
		pair<int,int>pre(1e9,1e9);
		bool sameflag = false;
		for (int i = 0; i < N; ++i) {
			int mydif;cin>>mydif;
			bool ok=false;
			int mytime=-1;
			for (int j = 0; j < 2000; ++j) {
				mytime=j*mydif;
				if (mytime > M) {
					mytime -= mydif;
					break;
				}
				if (pre > make_pair(mytime, mydif)) {
				}
				else if (pre == make_pair(mytime, mydif)) {
				}
				else {
					break;
				}
			}
			if (pre < make_pair(mytime, mydif)) {

			}
			else if (pre == make_pair(mytime, mydif)) {
				sameflag=true;
			}
			else {
				sameflag=false;
				pre=make_pair(mytime,mydif);
				ans=i;
			}
		}
		if(sameflag)ans=N-1;
		cout<<ans+1<<endl;
	}
	return 0;
}