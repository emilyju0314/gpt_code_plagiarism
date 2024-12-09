#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
struct Trie {
	Trie *next[2];
	Trie() {
		next[0] = next[1] = NULL;
	}
	void insert(char *s) {
		if (*s == '\0') return;
		if (this->next[*s - '0'] == NULL)
			this->next[*s - '0'] = new Trie();
		this->next[*s - '0']->insert(s + 1);
	}
};
vector<LL> item;
LL L;
char s[100001];
void dfs(Trie *t, int d) {
	int cnt = 0;
	if (t->next[0] != NULL) {
		dfs(t->next[0], d + 1);
		cnt++;
	}
	if (t->next[1] != NULL) {
		dfs(t->next[1], d + 1);
		cnt++;
	}
	if (cnt == 1) item.push_back(L - d);
}
int main() {
	int N;
	cin >> N >> L;
	Trie t;
	for (int i = 0; i < N; i++) {
		cin >> s;
		t.insert(s);
	}
	dfs(&t, 0);
	LL g = 0;
	for (int i = 0; i < item.size(); i++) {
		int k = 0;
		while (item[i] % 2 == 0) {
			item[i] /= 2;
			k++;
		}
		g ^= (1LL << k);
	}
	if (g == 0) {
		cout << "Bob" << endl;
	}
	else {
		cout << "Alice" << endl;
	}
}