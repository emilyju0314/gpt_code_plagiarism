#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int path[10][10];
int cost[10][10];
int maximum = 0;
int current = 0;
vector<int> pa;
vector<int> mapa;
int n,m;

int p[20];
int memo[1<<20];

int Abs(int x){
	return x < 0 ? -x : x;
}
int dfs(int bit){
	if( memo[bit] != -1 ) return memo[bit];
	
	vector<int> card;
	for(int i = 0 ; i < 20 ; i++)
		if( bit >> i & 1 )
			card.push_back(i);
	
	int ans = __builtin_popcount(bit);
	for(int i = 0 ; i < card.size() ; i++){
		for(int j = i+1 ; j < card.size() ; j++){
			if( p[card[i]] == p[card[j]] ){
				int dx = Abs(i%4-j%4);
				int dy = Abs(i/4-j/4);
				if( max(dx,dy) <= 1 ) ans = min( ans , dfs(bit-(1<<card[i])-(1<<card[j])) );

			}
		}
	}
	return memo[bit] = ans;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		memset(memo,-1,sizeof(memo));
		for(int i = 0 ; i < 20 ; i++) cin >> p[i];
		cout << dfs((1<<20)-1) << endl;
	}
}