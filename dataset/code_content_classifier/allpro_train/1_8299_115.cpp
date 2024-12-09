#include <bits/stdc++.h>
using namespace std;
int R, C, N; 
vector<pair<int, long long>> E[200010]; 
long long A[200010];  
bool seen[200010];
bool ok = true; 
long long mnr, mnc; 
long long INF = 1145141919810364364; 
void dfs(int i, long long &mnr, long long &mnc){
	seen[i] = true; 
	for(auto v : E[i]){
		if(A[v.first] != INF && A[i] + A[v.first] != v.second){
			ok = false; return; 	
		}
		if(A[v.first] != INF) continue; 
		A[v.first] = v.second - A[i]; 
		if(v.first < R) mnr = min(mnr, A[v.first]); 
		else mnc = min(mnc, A[v.first]); 
		dfs(v.first, mnr, mnc); 
	}
}
int main(){
	cin >> R >> C >> N; 
	fill(A, A+R+C, INF);
	while(N--){
		int r, c; long long a; 
		cin >> r >> c >> a; 
		r--; c--; 
		E[r].push_back(make_pair(R+c, a)); 
		E[R+c].push_back(make_pair(r, a)); 
	}
	for(int i = 0; i < R+C; i++){
		if(seen[i]) continue; 
		if(i < R){
			mnr = 0; mnc = INF;  
		}else{
			mnc = 0; mnr = INF; 
		}
		A[i] = 0; 
		dfs(i, mnr, mnc); 
		if(mnr + mnc < 0) ok = false; 
	}
	cout << (ok ? "Yes" : "No") << endl; 
}