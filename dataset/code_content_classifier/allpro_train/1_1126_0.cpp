#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <algorithm>
#include <cctype>
#include <cstdlib>
using namespace std;

typedef long long LL;

const LL inf = LLONG_MAX / 2;

struct node{
	char ch;
	LL refcnt;
	LL len;
	vector<node*> to;
	
	node(char c, LL r = 0, LL len = -1)
	: ch(c), refcnt(r), len(len) {}
};

struct state{
	int stnum;
	node *nd;
	LL a, b;
	size_t cntr;
	
	state(int s, node *nd, LL a, LL b, size_t c)
	: stnum(s), nd(nd), a(a), b(b), cntr(c) {}
};

node *alp[26];
node emp(0, inf, 0);
string ans;

node *getnode(int c){
	if(c == '.'){ return &emp; }
	node *&ret = alp[c - 'a'];
	if(!ret){ ret = new node(c); }
	return ret;
}

void delnode(node *nd){
	queue<node*> q;
	q.push(nd);
	while(q.empty()){
		nd = q.front();
		q.pop();
		for(size_t i = 0; i < nd->to.size(); ++i){
			node *next = nd->to[i];
			if(!--next->refcnt){
				q.push(next);
			}
		}
		delete nd;
	}
}


void dfs(node *nd0, LL a0, LL b0){
	stack<state> stk;
	stk.push(state(0, nd0, a0, b0, 0));
	while(!stk.empty()){
		state &tp = stk.top();
		int &num = tp.stnum;
		node *&nd = tp.nd;
		LL &a = tp.a;
		LL &b = tp.b;
		size_t &cntr = tp.cntr;

		if(num == 0){
			if(a >= b){
				stk.pop();
				continue;
			}
			if(nd->ch){
				nd->len = 1;
				if(a == 0){
					ans += nd->ch;
				}
				stk.pop();
				continue;
			}
			if(nd->len >= 0 && nd->len <= a){
				stk.pop();
				continue;
			}

			nd->len = 0;
			num = 1;
		}
		else if(num == 1){
			if(cntr >= nd->to.size()){
				stk.pop();
				continue;
			}
			node *next = nd->to[cntr];
			
			while(next->to.size() == 1){
				node *tmp = next;
				nd->to[cntr] = next->to[0];
				next = next->to[0];

				if(--tmp->refcnt){
					++next->refcnt;
					break;
				}

				delete tmp;
			}

			num = 2;
			stk.push(state(0, next, a, b, 0));
		}
		else if(num == 2){
			node *next = nd->to[cntr];
			LL olen = next->len;
			a = max(a - olen, 0LL);
			b = max(b - olen, 0LL);
			nd->len = min(nd->len + olen, inf);

			if(next->len == 0){
				nd->to.erase(nd->to.begin() + cntr);
				--cntr;
				if(!--next->refcnt){
					delnode(next);
				}
			}
			
			++cntr;
			num = 1;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);

	string s;
	LL q, a, b;
	char c;
	cin >> s >> q >> a >> b;
	--a;

	node *root = new node(0);
	root->to.resize(s.size());
	for(size_t i = 0; i < s.size(); ++i){
		node *next = getnode(s[i]);
		root->to[i] = next;
		++next->refcnt;
	}

	for(LL i = 0; i < q; ++i){
		cin >> c >> s;
		node *nd = alp[c - 'a'];
		if(!nd){ continue; }
		alp[c - 'a'] = 0;

		nd->ch = 0;
		nd->to.resize(s.size());
		for(size_t j = 0; j < s.size(); ++j){
			node *next = getnode(s[j]);
			nd->to[j] = next;
			++next->refcnt;
		}
	}

	dfs(root, a, b);
	if(ans.size() < b - a){
		ans = ".";
	}
	cout << ans << '\n';
	
	delnode(root);
}