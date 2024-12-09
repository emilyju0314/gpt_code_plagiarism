#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1000000007;
int c[400];
int ans[400][400];

int main() {
  int H,W,K;
  cin >> H >> W >> K;
  vector<string> s(400);
  vector<vector<int>> as(400);
  for(int i=0;i<H;i++){cin >> s[i];}
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(s[i][j]=='#'){
        c[i]++; as[i].push_back(j);
      }
    }
    as[i].push_back(400);
  }
  int count=1;
  for(int i=0;i<H;i++){
    int memo1=i;
    while(i<H && c[i]==0){i++;}
    int memo2=i;
    while(i+1<H && c[i+1]==0){i++;}
    int memo3=i+1;
    int cc=1;
    for(int j=0;j<W;j++){
      if(j>=as[memo2][cc]){count++; cc++;}
      for(int k=memo1;k<memo3;k++){ans[k][j]=count;}
    }
    count++;
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){cout << ans[i][j] << " ";}
    cout << endl;
  }
}