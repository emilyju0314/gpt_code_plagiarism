#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<int> vi;
const double EPS = 1e-5;

typedef double Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;

void pMat(Matrix &a){
	REP(i,a.size()){
		REP(j,a[0].size()) cout << a[i][j] << ":";
		cout << endl;
	}
	cout << endl << endl;
}

Matrix mul(const Matrix &a, const Array &b){
	Matrix res(a.size(), Array(1));
	REP(i, a.size()){
		REP(k, a[0].size()){
				res[i][0] += a[i][k] * b[k];
		}
	}
	return res;
}
struct LUinfo {
  vector<Number> value;
  vector<int> index;
};
LUinfo LU_decomposition(Matrix A) {
  const int n = A.size();
  LUinfo data;
  for (int i = 0; i < n; ++i) {
    int pivot = i;
    for (int j = i+1; j < n; ++j)
      if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
    swap(A[pivot], A[i]);
    data.index.push_back(pivot);
    for(int j = i+1; j < n; ++j) {
      A[j][i] /= A[i][i];
      for(int k = i+1; k < n; ++k)
        A[j][k] -= A[i][k] * A[j][i];
      data.value.push_back(A[j][i]);
    }
  }
  for(int i = n-1; i >= 0; --i) {
    for(int j = i+1; j < n; ++j)
      data.value.push_back(A[i][j]);
    data.value.push_back(A[i][i]);
  }
  return data;
}
Array LU_backsubstitution(const LUinfo &data, Array b) {
  const int n = b.size();
  int k = 0;
  for (int i = 0; i < n; ++i){
    swap(b[data.index[i]], b[i]);
    for(int j = i+1; j < n; ++j)
      b[j] -= b[i] * data.value[k++];
  }
  for (int i = n-1; i >= 0; --i) {
    for (int j = i+1; j < n; ++j)
      b[i] -= b[j] * data.value[k++];
    b[i] /= data.value[k++];
  }
  return b;
}


int d;

int calc(){
	vector<double> v(d+3);
	int ds = d+1;
	REP(i, d+3) cin >> v[i];
	REP(i, d+3){
		for(int j = i + 1; j < d+3; j++){
			Matrix A(ds, Array(ds, 0));
			Array B(ds);
			int id = 0;
			REP(k, d+3){
				if(k == i || k == j) continue;
				REP(l, ds) A[id][l] = pow(k, ds-l-1);
				B[id] = v[k];
				id++;
			}
			Array y = LU_backsubstitution(LU_decomposition(A), B);
			Matrix C(2, Array(ds, 0));
			REP(l, ds) C[0][l] = pow(i, ds-l-1);
			REP(l, ds) C[1][l] = pow(j, ds-l-1);
			
			Matrix z = mul(C, y);
/*
cout << "i : " << i << "j : " << j << endl;
cout << "C : " << endl;
pMat(C);
cout << "z : " << endl;
pMat(z);
*/
			if((abs(z[0][0] - v[i]) < EPS) && (abs(z[1][0] - v[j]) > EPS)) return j;
			if((abs(z[0][0] - v[i]) > EPS) && (abs(z[1][0] - v[j]) < EPS)) return i;
		}
	}
	return -1;
}

int main(void){
	while(cin>>d, d){
		cout << calc() << endl;
	}
	return 0;
}