#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define ALL(container) container.begin(), container.end()
#define X first
#define Y second
pii operator+(const pii &s, const pii &t){ return pii(s.first+t.first, s.second+t.second);}
pii operator-(const pii &s, const pii &t){ return pii(s.first-t.first, s.second-t.second);}


pii d[7] = {pii(0, -1),pii(1, -1),pii(1, 0),pii(0, 1),pii(-1, 1),pii(-1, 0),pii(0, 0)};

vector<vector<pii>> Body[9];
vector<vector<pii>> g[9];

inline int abs(const pii &d){
	return ((d.X < 0) ^ (d.Y < 0)) ? max(abs(d.X), abs(d.Y)) : abs(d.X) + abs(d.Y);
}

inline int abs(const pii &p1, const pii &p2){
	return abs(p1 - p2);
}

void enumerateState(vector<pii> &p){
	Body[p.size()].push_back(p);
	if(p.size() == 8) return;
	const pii b = p.back();
	p.emplace_back();
	REP(i, 6){
		const pii q = b + d[i];
		p.back() = q;
		int f = 1;
		RREP(j, (int)p.size()-2) if(abs(p[j], q) <= 1) f = 0;
		if(f) enumerateState(p);
	}
	p.pop_back();
}

void makeGraph(){
	REPS(k, 8){
		const int n = Body[k].size();
		g[k].resize(n);
		REP(i, n)REP(j, i)REP(l, 7){
			int f = 1, prev = l != 6;
			for(int q=1;q<k&&f;q++){
				const int dist = abs(Body[k][j][q], Body[k][i][q] - d[l]);
				if(dist > 1 || (dist == 1 && prev)) f = 0;
				prev = dist;
			}
			if(f){
				g[k][i].emplace_back(j, l);
				g[k][j].emplace_back(i, l==6 ? l : (l+3)%6);
			}
		}
	}
}

struct State{
	pii pos;
	int id, cost;
	State(pii pos=pii(0, 0), int id=0, int cost=0):pos(pos), id(id), cost(cost){}
};

int n, m, visited[60][60][4100], Rock[60][60];
pii goal;

int main(){
	ios::sync_with_stdio(false);
	vector<pii> p(1, pii(0, 0));
	enumerateState(p);
	makeGraph();
	while(cin >> n, n){
		vector<pii> body(n);
		REP(i, n) cin >> body[i].X >> body[i].Y;
		pii pos = pii(30, 30);
		memset(Rock, 0, sizeof(Rock));
		memset(visited, 0, sizeof(visited));
		cin >> m;
		REP(i, m){
			pii t;
			cin >> t.X >> t.Y; t = t - body[0] + pos;
			if(abs(t, pos) > 25) continue;
			Rock[t.X][t.Y] = 1;
		}
		cin >> goal.X >> goal.Y; goal = goal - body[0] + pos;
		RREP(i, n) body[i] = body[i] - body[0];
		int state = find(ALL(Body[n]), body) - Body[n].begin();
		
		visited[pos.X][pos.Y][state] = 1;
		queue<State> que;
		que.emplace(pos, state, 0);
		int ans = 20;
		while(!que.empty()){
			State s = que.front();que.pop();
			if(s.pos == goal){
				ans = s.cost;
				break;
			}
			FOR(it, g[n][s.id]){
				State t(s.pos + d[it->second], it->first, s.cost+1);
				if(t.cost + abs(t.pos, goal) >= 20 || visited[t.pos.X][t.pos.Y][t.id]) continue;
				visited[t.pos.X][t.pos.Y][t.id] = 1;
				int f = 1;
				REP(i, n) if(Rock[t.pos.X+Body[n][t.id][i].X][t.pos.Y+Body[n][t.id][i].Y]) f = 0;
				if(f) que.push(t);
			}
		}
		cout << ans << endl;
	}
	return 0;
}