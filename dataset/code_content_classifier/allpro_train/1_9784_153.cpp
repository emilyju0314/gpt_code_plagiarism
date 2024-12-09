#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>

#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;

string rotate(string t, int s, int e, int d) {
	string nt(t);
	for(int i=s; i<=e; i++) {
		nt[i] = '0' + (nt[i]-'0'+d)%10;
	}
	return nt;
}

int main()
{
next:
	for(;;) {
		int k;
		cin >> k;
		if(k==0) return 0;
		string from, to;
		cin >> from >> to;
		if(from==to) {
			printf("0\n");
			continue;
		}
		set<string> vi;
		queue<pair<int, string> > q;
		q.push(make_pair(0, from));
		vi.insert(from);
		while(!q.empty()) {
			int c = q.front().first;
			string v = q.front().second;
			q.pop();
			rep(i, k) if(v[i]!=to[i]) {
				for(int j=i; j<k; j++) {
					string nv = rotate(v, i, j, (to[i]-v[i]+10)%10);
					if(nv==to) {
						printf("%d\n", c+1);
						goto next;
					}
					if(vi.find(nv)!=vi.end()) continue;
					vi.insert(nv);
					q.push(make_pair(c+1, nv));
				}
				break;
			}
		}
	}
}