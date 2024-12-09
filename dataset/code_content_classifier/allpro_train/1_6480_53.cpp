#include <bits/stdc++.h>
using namespace std;
#define Rep(i,N) for(int i = 0; i < N;i++)
typedef pair<int,int> Pi;
#define F first
#define S second
#define INF 1 << 28

inline void chmax(int &a,int b) {
  a = max(a,b);
}

inline void chmin(int &a,int b) {
  a = min(a,b);
}

int main()
{
  int A, B, C, N;
  while(cin >> A >> B >> C, A || B || C) {
    int data[1005][3], r[1005];
    int flag[305];
    fill(flag,flag + 305,2);
    
    cin >> N;
    Rep(i,N) {
      Rep(j,3) {
	cin >> data[i][j];
	data[i][j]--;
      }
      cin >> r[i];
      if(r[i]) {
	Rep(j,3)flag[data[i][j]] = 1;
      }
    }
    Rep(i,N) {
      if(r[i])continue;
      int cnt = 0;
      int f;
      Rep(j,3) {
	if(flag[data[i][j]] == 1)cnt++;
	else f = j;
      }
      if(cnt == 2)flag[data[i][f]] = 0;
    }
    Rep(i,A + B + C) {
      cout << flag[i] << endl;
    }
  }
  return 0;
}
    
      