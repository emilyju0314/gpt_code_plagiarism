#include<iostream>
#include<stack>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef vector<int> vi;

int n;
int b[10][10];
stack<vi> ans;
int sx[] = {-1,0,1,0}, sy[] = {1,1,1,2};
int mx[] = {1,2,0,1,2,0,1,2}, my[] = {0,0,1,1,1,2,2,2};
int lx[] = {-1,0,1,-2,-1,0,1,2,-1,0,1,0}, ly[] = {1,1,1,2,2,2,2,2,3,3,3,4};

bool rec(int d){
  if(d==n){
    rep(i,10)rep(j,10)if(b[i][j])return false;
    return true;
  }

  rep(i,10)rep(j,10){
    if(b[i][j]){
      b[i][j]--;
      bool flag = false;
      if(i<6 && j>1 && j<8){
	bool f = true;
	rep(k,12){
	  if(!b[i+ly[k]][j+lx[k]]){ f = false; break; }
	}
	
	if(f){
	  rep(k,12)b[i+ly[k]][j+lx[k]]--;
	  vi v(3); v[0] = j; v[1] = i+2; v[2] = 3;
	  ans.push(v);
	  if(rec(d+1))return true;
	  ans.pop();
	  rep(k,12)b[i+ly[k]][j+lx[k]]++;
	  flag = true;
	}
      }

      if(i<8 && j<8){
	bool f = true;
	rep(k,8){
	  if(!b[i+my[k]][j+mx[k]]){ f = false; break; }
	}
	
	if(f){
	  rep(k,8)b[i+my[k]][j+mx[k]]--;
	  vi v(3); v[0] = j+1; v[1] = i+1; v[2] = 2;
	  ans.push(v);
	  if(rec(d+1))return true;
	  ans.pop();
	  rep(k,8)b[i+my[k]][j+mx[k]]++;
	  flag = true;
	}
      }

      if(i<8 && j>0 && j<9){
	bool f = true;
	rep(k,4){
	  if(!b[i+sy[k]][j+sx[k]]){ f = false; break; }
	}
	
	if(f){
	  rep(k,4)b[i+sy[k]][j+sx[k]]--;
	  vi v(3); v[0] = j; v[1] = i+1; v[2] = 1;
	  ans.push(v);
	  if(rec(d+1))return true;
	  ans.pop();
	  rep(k,4)b[i+sy[k]][j+sx[k]]++;
	  flag = true;
	}
      }
      b[i][j]++;
      if(!flag)return false;
    }
  }
  return false;
}

int main(){
  cin >> n;
  rep(i,10)rep(j,10)cin >> b[i][j];

  rec(0);

  while(ans.size()){
    vi v = ans.top(); ans.pop();
    cout << v[0] << " " << v[1] << " " << v[2] << endl;
  }
}