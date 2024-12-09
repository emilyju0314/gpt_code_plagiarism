#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define TARO 0
#define HANAKO 1

int main() {
	int n;
	
	while (cin >> n, n) {
		set< int > card[2];
		
		for_(i,0,2*n) card[HANAKO].insert(i + 1);
		
		for_(i,0,n) {
			int c;
			cin >> c;
			card[TARO].insert(c);
		}
		
		for (int t : card[TARO]) card[HANAKO].erase(t);
		
		int cur = -1, turn = 0;
		
		while (card[TARO].size() > 0 && card[HANAKO].size() > 0) {
			if (cur == -1) {
				cur = *card[turn % 2].begin();
				card[turn % 2].erase(cur);
			} else {
				set< int >::iterator it = card[turn % 2].upper_bound(cur);
				
				if (it == card[turn % 2].end()) {
					cur = -1;
				} else {
					cur = *it;
					card[turn % 2].erase(cur);
				}
			}
			
			++turn;
		}
		
		cout << card[HANAKO].size() << endl << card[TARO].size() << endl;
	}
}