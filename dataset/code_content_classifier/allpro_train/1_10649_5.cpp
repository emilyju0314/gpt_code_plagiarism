#include <bits/stdc++.h>
 
using namespace std;
 
const int vy[] = {0, 1, 0, -1}, vx[] = {1, 0, -1, 0};
 
int H, W;
string S[40];
bool v[40][40];
 
void dfs(int y, int x)
{
  v[y][x] = true;
  if(S[y][x] == '*') return;
  if(S[y][x] == '#') S[y][x] = '.';
  for(int i = 0; i < 4; i++) {
    int ny = vy[i] + y, nx = vx[i] + x;
    if(ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
    if(S[ny][nx] == '.') continue;
    if(v[ny][nx]) continue;
    dfs(ny, nx);
    return;
  }
  return;
}
 
int main()
{
  cin >> H >> W;
  int sy, sx;
  for(int i = 0; i < H; i++) {
    cin >> S[i];
    for(int j = 0; j < W; j++) {
      if(S[i][j] == '@') {
        sy = i;
        sx = j;
      }
    }
  }
 
  for(int j = 0; j < W; j++) {
    if(S[0][j] == '.') S[0][j] = '#';
  }
  if(S[1][0] == '.') S[1][0] = '#';
  if(S[1][W - 1] == '.') S[1][W - 1] = '#';
  for(int i = 2; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(j % 2 == 0) {
        if(S[i][j] == '.') S[i][j] = '#';
      } else {
        if(i == 2 && j % 4 == 3) S[i][j] = '#';
        else if(i == H - 1 && j % 4 == 1) S[i][j] = '#';
      }
    }
  }
 
  dfs(sy, sx);
 
  for(int i = 0; i < H; i++) {
    cout << S[i] << endl;
  }
}