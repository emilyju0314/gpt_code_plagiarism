#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define FOR(i,s,n) for(int i=s; i<n; i++)
#define ALL(x) x.begin(), x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	int n;
	cin >> n;
	rep(i, n) {
		vector<int> num(9);
		vector<string> mark(9);
		rep(j, 9) {
			cin >> num[j];
		}
		rep(j, 9) {
			cin >> mark[j];
		}
		vector<int> per(9);
		rep(j,9) per[j] = j;
		bool found = false;
		while( next_permutation(per.begin(), per.end()) ) {
			bool fail = false;
			rep(j,3) {
				rep(k,3) {
					if( mark[per[j*3]] != mark[per[j*3+k]] ) fail = true;
				}
				if( !(num[per[j*3]] == num[per[j*3+1]] && num[per[j*3]] == num[per[j*3+2]]) &&
					!(num[per[j*3]]+1 == num[per[j*3+1]] && num[per[j*3]]+2 == num[per[j*3+2]]) ) {
					fail = true;
				}

			}
			if(!fail) {
				cout << "1" << endl;
				found = true;
				break;
			}
		}
		if(!found) {
			cout << "0" << endl;
		}
	}
	return 0;
}