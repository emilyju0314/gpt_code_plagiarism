#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

vector <pii> V[111];
vector <int> X;
int A[111][111], B[111][111], C[111][111], M[111];
bool chk1[111], chk2[111];
int n, m;

bool match(int p)
{
	chk1[p] = true;
	
	for(pii &t: V[p]){
		if(M[t.first] == -1 || (!chk1[M[t.first]] && match(M[t.first]))){
			M[t.first] = p; return 1;
		}
	}
	
	return 0;
}

int main()
{
	int i, j, k, f;
	
	scanf("%d%d", &n, &m);
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d", A[i] + j);
			A[i][j] --;
			V[i].emplace_back(A[i][j] / m, A[i][j]);
		}
	}
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			chk2[j] = false; M[j] = -1;
		}
		
		for(f=1; f; ){
			for(j=0; j<n; j++){
				chk1[j] = false;
			}
			
			f = 0;
			
			for(j=0; j<n; j++){
				if(!chk1[j] && !chk2[j] && match(j)){
					chk2[j] = true; f = 1;
				}
			}
		}
		
		for(j=0; j<n; j++){
			for(k=0; k<V[j].size(); k++){
				if(M[V[j][k].first] == j) break;
			}
			
			B[j][i] = V[j][k].second;
			swap(V[j][k], V[j].back());
			V[j].pop_back();
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%d ", B[i][j] + 1);
		}
		printf("\n");
	}
	
	for(i=0; i<m; i++){
		X.clear();
		
		for(j=0; j<n; j++){
			X.push_back(B[j][i]);
		}
		
		sort(X.begin(), X.end());
		
		for(j=0; j<n; j++){
			C[j][i] = X[j];
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%d ", C[i][j] + 1);
		}
		printf("\n");
	}
	
	return 0;
}