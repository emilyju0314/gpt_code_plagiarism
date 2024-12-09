#include<bits/stdc++.h>
using namespace std;
typedef pair< int , int > Pi;
  
/* 入力 */
int h, w, d, n; // h:縦 w:横 d:正方形の個数 n:Dマシン使用回数
char t[50][50]; // マップ
int r[10]; // r[i]:i番目の正方形の半径
int x[50], y[50], s[50]; // (x[i],y[i])に反応s[i]があった(小並感)
/* おわり */
  
int sx, sy; // Dの位置
bool go[50][50]; // いけたらtrue
bool used[50][50];
  
bool isin( int nx, int ny, int x, int y, int s){
  return ny >= y - s && ny <= y + s  && nx >= x - s  && nx <= x + s ;
}
bool isout( int nx, int ny, int x, int y, int s){
  return !isin( nx, ny, x, y, s);
}
  
void all_AND(){
  fill_n( *go, 50 * 50, true);
  for(int i = 0; i < n; i++){ //頑張ってＡＮＤやれば勝ちだろうけど
    if(s[i] == d){ //外にある
      for(int j = 0; j < h; j++){
        for(int k = 0; k < w; k++){
          if(isin( k, j, x[i], y[i], r[d - 1])) go[j][k] = false;
        }
      }
    }else if(s[i] == 0){ //中にある
      for(int j = 0; j < h; j++){
        for(int k = 0; k < w; k++){
          if(isout( k, j, x[i], y[i], r[0])) go[j][k] = false;
        }
      }
    }else{
      for(int j = 0; j < h; j++){
        for(int k = 0; k < w; k++){
          if(isout( k, j, x[i], y[i], r[s[i]])) go[j][k] = false;
          if(isin( k, j, x[i], y[i], r[s[i] - 1])) go[j][k] = false;
        }
      }
    }
  }
}
bool isover( int y, int x){
  return y < 0 || y >= h || x < 0 || x >= w;
}
void bfs(){
  fill_n( *used, 50 * 50, false);
  const int dy[] = { 1, 0, -1, 0}, dx[] = { 0, 1, 0, -1};
  queue< Pi > que;
  que.push( Pi( sy, sx));
  while(!que.empty()){
    Pi p = que.front();
    que.pop();
    if(used[p.first][p.second]++) continue;
    for(int i = 0; i < 4; i++){
      int ny = p.first + dy[i], nx = p.second + dx[i];
      if(!isover(ny,nx) && t[ny][nx] != '#') que.push( Pi( ny, nx));
    }
  }
  return;
}
  
int main(){
  cin >> h >> w >> d >> n;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> t[i][j];
      if(t[i][j] == 'D') sx = j, sy = i;
    }
  }
  for(int i = 0; i < d; i++){
    cin >> r[i];
  }
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i] >> s[i];
  }
  
  all_AND();
  int cnt = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(t[i][j] == '#') continue;
      cnt += go[i][j];
    }
  }
  if(cnt == 0) cout << "Broken\n";
  else{
    bfs();
    bool goflag = false;
    bool noflag = false;
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        //   cout << go[i][j];
        if(t[i][j] != '#' && go[i][j]){
          if(used[i][j]) goflag = true;
          else noflag = true;
        }
      }
      //cout << endl;
    }
    if(goflag && noflag) cout << "Unknown" << endl;
    else if(goflag) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return(0);
}