#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

class Dice {
	int face[6];
	void roll(int a, int b, int c, int d){
		int tmp = face[a];
		face[a] = face[b];
		face[b] = face[c];
		face[c] = face[d];
		face[d] = tmp;
	}
public:
	static const int TOP = 0, BACK = 1, LEFT = 2;
	static const int FRONT = 3, RIGHT = 4, BOTTOM = 5;
	Dice(){
		for(int i = 0; i < 6; ++i){ face[i] = i; }
	}
	int operator[](int index) const { return face[index]; }
	void roll_x_inc(){ roll(TOP, LEFT, BOTTOM, RIGHT); }
	void roll_x_dec(){ roll(TOP, RIGHT, BOTTOM, LEFT); }
	void roll_y_inc(){ roll(TOP, BACK, BOTTOM, FRONT); }
	void roll_y_dec(){ roll(TOP, FRONT, BOTTOM, BACK); }
	void roll_z_inc(){ roll(FRONT, LEFT, BACK, RIGHT); }
	void roll_z_dec(){ roll(FRONT, RIGHT, BACK, LEFT); }
	static vector<Dice> enumerate(){
		vector<Dice> ret;
		Dice d;
		for(int i = 0; i < 6; ++i){
			for(int j = 0; j < 4; ++j){
				ret.push_back(d);
				d.roll_z_inc();
			}
			if(i & 1){
				d.roll_y_inc();
			}else{
				d.roll_x_inc();
			}
		}
		return ret;
	}
};

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };

bool between(int a, int b, int c){
	return a <= b && b < c;
}

int cell_dir(char c){
	switch(c){
		case '+': return 15;
		case '|': return 10;
		case '-': return 5;
		case '<': return 4;
		case '>': return 1;
		case '^': return 2;
		case 'v': return 8;
	}
	return 0;
}

int make_graph(
	const vector<string> &field,
	vector< vector<pii> > &conn, vector<int> &tops)
{
	int H = field.size(), W = field[0].size();
	conn.resize(H * W * 24);
	tops.resize(24);
	vector< vector<int> > roll_table(6, vector<int>(6));
	vector<Dice> dices = Dice::enumerate();
	int start_face = 0;
	for(int i = 0; i < dices.size(); ++i){
		if(dices[i][Dice::TOP] == 0 && dices[i][Dice::BACK] == 1){
			start_face = i;
		}
		roll_table[dices[i][Dice::TOP]][dices[i][Dice::FRONT]] = i;
		tops[i] = dices[i][Dice::TOP];
	}
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			int dir = cell_dir(field[i][j]);
			for(int k = 0; k < 4; ++k){
				if(!(dir & (1 << k))){ continue; }
				int nr = i + dy[k], nc = j + dx[k];
				if(!between(0, nr, H) || !between(0, nc, W)){ continue; }
				for(int l = 0; l < 24; ++l){
					Dice d = dices[l];
					switch(k){
						case 0: d.roll_x_inc(); break;
						case 1: d.roll_y_dec(); break;
						case 2: d.roll_x_dec(); break;
						case 3: d.roll_y_inc(); break;
					}
					int nd = roll_table[d[Dice::TOP]][d[Dice::FRONT]];
					int cur = ((i * W) + j) * 24 + l;
					int next = ((nr * W) + nc) * 24 + nd;
					conn[next].push_back(pii(cur, dices[l][Dice::TOP]));
				}
			}
		}
	}
	return start_face;
}

bool is_reachable(const vector< vector<pii> > &conn, int start, int goal){
	int n = conn.size();
	vector<bool> passed(n);
	queue<int> q;
	q.push(start);
	passed[start] = true;
	while(!q.empty()){
		int p = q.front();
		if(p == goal){ return true; }
		q.pop();
		for(int i = 0; i < conn[p].size(); ++i){
			if(passed[conn[p][i].first]){ continue; }
			passed[conn[p][i].first] = true;
			q.push(conn[p][i].first);
		}
	}
	return false;
}

int count_reachable(const vector< vector<pii> > &conn, const vector<int> &goals){
	int n = conn.size();
	vector<bool> passed(n);
	queue<int> q;
	for(int i = 0; i < goals.size(); ++i){
		passed[goals[i]] = true;
		q.push(goals[i]);
	}
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int i = 0; i < conn[p].size(); ++i){
			if(passed[conn[p][i].first]){ continue; }
			passed[conn[p][i].first] = true;
			q.push(conn[p][i].first);
		}
	}
	int answer = 0;
	for(int i = 0; i < n; ++i){
		if(passed[i]){ ++answer; }
	}
	return answer;
}

int main(){
	int H, W;
	cin >> H >> W;
	vector<string> field(H);
	for(int i = 0; i < H; ++i){ cin >> field[i]; }
	vector<string> face(6);
	int maxlen = 0;
	for(int i = 0; i < 6; ++i){
		cin >> face[i];
		maxlen = max(maxlen, (int)face[i].size());
	}
	int Rs, Cs, Rd, Cd;
	cin >> Rs >> Cs >> Rd >> Cd;
	--Rs; --Cs; --Rd; --Cd;
	vector< vector<pii> > conn;
	vector<int> tops;
	int start = make_graph(field, conn, tops);
	start += ((Rs * W) + Cs) * 24;
	vector<int> goals;
	for(int i = 0; i < 24; ++i){
		int node = ((Rd * W) + Cd) * 24 + i;
		if(is_reachable(conn, node, start)){ goals.push_back(node); }
	}
	if(goals.size() == 0){
		cout << "no" << endl;
		return 0;
	}
	int n = conn.size();
	vector<string> mincost(conn.size());
	vector<bool> is_goal(conn.size());
	for(int i = 0; i < goals.size(); ++i){
		mincost[goals[i]] = face[tops[goals[i] % 24]];
		is_goal[goals[i]] = true;
	}
	int internal_n = count_reachable(conn, goals);
	for(int t = 0; t < internal_n * (maxlen + 1); ++t){
		vector<string> mc(mincost);
		bool modified = false;
		for(int i = 0; i < n; ++i){
			if(mincost[i] == ""){ continue; }
			for(int j = 0; j < conn[i].size(); ++j){
				int from = i, to = conn[i][j].first;
				int top = conn[i][j].second;
				if(mincost[to] == "" || mc[to] > face[top] + mincost[from]){
					mc[to] = face[top] + mincost[from];
					modified = true;
					if(to == start && t >= internal_n){
						cout << "infinite" << endl;
						return 0;
					}
				}
			}
		}
		mincost.swap(mc);
		if(!modified){ break; }
	}
	cout << mincost[start] << endl;
	return 0;
}