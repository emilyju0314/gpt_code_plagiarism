#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int h,w;
vector<vector<int>> d(400,vector<int>(400,1000));
void wf(){rep(k,h*w) rep(i,h*w) rep(j,h*w) d.at(i).at(j) = min(d.at(i).at(j), d.at(i).at(k) + d.at(k).at(j));}

int main() {
  int ans=0;
  cin >> h >> w;
  vector<char> s(h*w);
  for(int i=0;i<h*w;i++) cin >> s[i];
  for(int i=0;i<h*w;i++) d[i][i] = 0;
  for(int i=0;i<h;i++){
    for(int j=0;w>1 && j<(w-1);j++){
      if (s[i*w+j] == '.' && s[i*w+j+1] == '.'){
        d[i*w+j][i*w+j+1] = 1;
        d[i*w+j+1][i*w+j] = 1;
      }
    }
  }
  for(int i=0;i<w;i++){
    for(int j=0;h>1 && j<(h-1);j++){
      if (s[j*w+i] == '.' && s[j*w+i+w] == '.'){
        d[j*w+i][j*w+i+w] = 1;
        d[j*w+i+w][j*w+i] = 1;
      }
    }
  }
  wf();
  for(int i=0;i<h*w;i++) for(int j=0;j<h*w;j++) if(d[i][j] < 401) ans = max(ans,d[i][j]);
  cout << ans << endl;
}
