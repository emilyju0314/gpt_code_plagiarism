#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;

int main(){
  ll i,j,k,n,c,w,h;
  cin >> n >> c;
  ll d[c][c],col[n][n];
  for(i=0;i<c;i++){
    for(j=0;j<c;j++)cin >> d[i][j];
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)cin >> col[i][j];
  }

  ll a[3]={};
  ll ret = 1e9;
  ll pick[3][c];
  memset(pick,0,sizeof(pick));

  for(i=0;i<c;i++){
    for(h=0;h<n;h++){
      for(w=0;w<n;w++){
        pick[(h+w+2)%3][i]+=d[col[h][w]-1][i];
      }
    }
  }
  for(i=0;i<c;i++){
    for(j=0;j<c;j++){
      if(i==j)continue;
      for(k=0;k<c;k++){
        if(i==k || j==k)continue;
        ll sum = pick[0][i]+pick[1][j]+pick[2][k];
        ret = min(ret,sum);
      }
    }
  }
  cout << ret << endl;
  return 0;
}
