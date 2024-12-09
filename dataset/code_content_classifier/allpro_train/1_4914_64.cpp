#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

int n, m, a, b;
string ans[1080];

void tate(int x, int y){
  ans[x][y] = '^';
  ans[x+1][y] = 'v';
}

void yoko(int x, int y){
  ans[x][y] = '<';
  ans[x][y+1] = '>';
}

int main(){
  cin >> n >> m >> a >> b;
  for(int i = 0;i < n;i++)
    for(int j = 0;j < m;j++)
      ans[i] += ".";
  
  if(n % 2 == 1){
    for(int i = 0;i+1 < m;i+=2){
      if(a == 0)break;
      yoko(n-1,i);a--;
    }
  }
  
  if(m % 2 == 1){
    for(int i = 0;i+1 < n;i+=2){
      if(b == 0)break;
      tate(i, m-1);b--;
    }
  }

  for(int i = 0;i+1 < n;i+=2){
    for(int j = 0;j+1 < m;j+=2){
      if(a >= 2){
	yoko(i,j);
	yoko(i+1,j);
	a-=2;
      }
      else if(b >= 2){
	tate(i,j);
	tate(i,j+1);
	b-=2;
      }
      else if(a>0){
	yoko(i,j);
	a--;
      }
      else if(b>0){
	tate(i,j);
	b--;
      }
    }
  }

  if(b == 1 && n * m % 2 == 1 && ans[n-2][m-2] == '.'){
    tate(n-2,m-3);
    yoko(n-1, m-2);
    b--;
  }

  if(a > 0 || b > 0){
    cout << "NO" << endl;
  }
  else{
    cout << "YES" << endl;
    for(int i = 0;i < n;i++)cout << ans[i] << endl;
  }
  return 0;
}