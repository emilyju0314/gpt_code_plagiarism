#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int N;
v1 pre, in, post;
int pos = 0;
void sep(int i, int e){//i, j, eはin用, pはpre
	if(i>e) return;
	if(i == e){
		post.push_back(in[i]);
		pos++;
		return;
	}
	int root = pre[pos];
	pos++;
	int j = 0;
	while(in[j] != root){
		j++;
	}
	sep(i, j-1);
	sep(j+1, e);
	post.push_back(root);
}

void solve(){
	sep(0, N-1);
	rep(i, N){
		cout << post[i];
		if(i != N-1) cout << " ";
		if(i == N-1) cout << endl;
	}
}

int main(){
	 cin >> N;
	 rep(i, N){
		 int x;
		 cin >> x;
		 pre.push_back(x);
	 }
	 rep(i, N){
		 int x;
		 cin >> x;
		 in.push_back(x);
	 }
	 solve();
}

