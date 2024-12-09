#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

typedef unsigned uint;

vector<uint> st;

void enumerate(int i, uint use, uint S){
	if(i == 8){
		st.push_back(S);
	}
	else{
		for(int j = 0; j < 9; ++j){
			if(~use >> j & 1){
				enumerate(i + 1, use | 1 << j, S | j << (4 * i));
			}
		}
	}
}

inline int index(uint S){
	return lower_bound(st.begin(), st.end(), S) - st.begin();
}

int encode(const vector<uint> &v){
	uint S = 0;
	for(int i = 0; i < 8; ++i){
		S |= v[i] << (i * 4);
	}
	return index(S);
}

void decode(int idx, vector<uint> &v){
	uint x = 36;
	uint S = st[idx];
	for(int i = 0; i < 8; ++i){
		uint y = S >> (i * 4) & 15;
		v[i] = y;
		x -= y;
	}
	v[8] = x;
}

int input(){
	uint r = 0, x = 0;
	for(int i = 0; i < 8; ++i){
		scanf("%u", &x);
		r |= x << (i * 4);
	}
	scanf("%*u");
	return index(r);
}

int solve(int ch, int cv){
	typedef pair<int,int> pii;

	int first = input();
	int last = input();
	if(first == last){ return 0; }

	vector<int> dist(st.size(), 1000000000);
	dist[first] = 0;
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push(pii(0, first));
	
	int dif[4] = {1, 8, 3, 6};
	int cost[4] = {ch, ch, cv, cv};
	
	vector<uint> v1(9), v2(9);
	while(!pq.empty()){
		int idx = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if(dist[idx] != d){ continue; }
		if(idx == last){ return d; }

		decode(idx, v1);
		int zero = find(v1.begin(), v1.end(), 0u) - v1.begin();
		for(int i = 0; i < 4; ++i){
			v2 = v1;
			swap(v2[zero], v2[(zero + dif[i]) % 9]);
			int to = encode(v2);
			if(dist[to] > d + cost[i]){
				dist[to] = d + cost[i];
				pq.push(pii(dist[to], to));
			}
		}
	}
	throw 0;
}

int main(){
	enumerate(0, 0, 0);
	sort(st.begin(), st.end());

	int ch, cv;
	while(scanf("%d%d", &ch, &cv), ch){
		printf("%d\n", solve(ch, cv));
	}
}