#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
	int pos, chg, cost;
	Node(int pos, int chg, int cost) : pos(pos), chg(chg), cost(cost) {}
	bool operator < (const Node &nd) const { return cost > nd.cost; }
};

int main(){
	int n, m, c;
	static int len[100][100];
	while(cin >> n >> m >> c, n){
		vector< vector< pair<int,int> > > g(n);
		for(int i=0;i<m;i++){
			int f, t, c; cin >> f >> t >> c;
			g[f-1].push_back(make_pair(t-1, c));
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) len[i][j] = 1000000000;
		priority_queue<Node> qu; qu.push(Node(0, 0, 0));
		len[0][0] = 0;
		while(!qu.empty()){
			Node nd = qu.top(); qu.pop();
			int pos = nd.pos, chg = nd.chg, cost = nd.cost;
			if(len[pos][chg] < cost) continue;
			for(int i=0;i<g[pos].size();i++){
				int next = g[pos][i].first;
				if(len[next][chg] > len[pos][chg]+g[pos][i].second){
					len[next][chg] = len[pos][chg]+g[pos][i].second;
					qu.push(Node(next, chg, len[next][chg]));
				}
				if(chg+1 < n && len[next][chg+1] > len[pos][chg]){
					len[next][chg+1] = len[pos][chg];
					qu.push(Node(next, chg+1, len[next][chg+1]));
				}
			}
		}
		for(int i=1;i<n;i++){
			if(len[n-1][i] <= c){
				cout << i << endl;
				break;
			}
		}
	}
}