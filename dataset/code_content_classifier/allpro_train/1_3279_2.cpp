#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int inf = 1e9;

typedef long long int lli;
typedef vector<vector<lli> > Matrix;
bool mul(Matrix &a, Matrix &b, Matrix &c){ //A*B=C
	if(a[0].size() != b.size()) return false;
	int n = a.size();
	int m = b.size();
	int l = b[0].size();
	Matrix ret(n, vector<lli>(l,0));
	for(int i=0; i<n; i++){
		for(int j=0; j<l; j++){
			for(int k=0; k<m; k++){
				ret[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	c = ret;
	return true;
}

int main(){
	while(1){
		int n,m,a,b,c,t;
		cin >> n >> m >> a >> b >> c >> t;
		if(n==0) break;
		
		Matrix ini(n, vector<lli>(1));
		for(int i=0; i<n; i++){
			cin >> ini[i][0];
		}
		
		Matrix r(n, vector<lli>(n));
		Matrix mat(n, vector<lli>(n, 0));
		for(int i=0; i<n; i++){
			r[i][i] = b;
			mat[i][i]=1;
			if(i!=0) r[i][i-1] = a;
			if(i!=n-1) r[i][i+1] = c;
		}
		for(int i=log2(t); i>=0; i--){
			mul(mat, mat, mat);
			if((t&1<<i) != 0){
				mul(mat, r, mat);
			}
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					mat[j][k] = mat[j][k]%m;
				}
			}
		}
		
		mul(mat, ini, ini);
		for(int i=0; i<n-1; i++){
			cout << ini[i][0]%m << " ";
		}
		cout << ini[n-1][0]%m << endl;
	}
	return 0;
}