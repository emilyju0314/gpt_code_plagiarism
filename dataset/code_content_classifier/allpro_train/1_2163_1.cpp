#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef pair<int,int> ii;

int H,W,LP,LP_dir;
bool polluted_room[9][9];
bool visited[9][9];
char room[9][9];
int dx8[] = {+0,+1,+1,+1,+0,-1,-1,-1};//0   1    2  3     4  5    6   7
int dy8[] = {-1,-1,+0,+1,+1,+1,+0,-1};//上、右上、右、右下、下、左下、左、左上
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
vector<int> statue;

inline bool isMirror(int x,int y) { 
  return ( room[y][x] == '/' || room[y][x] == '\\' || room[y][x] == '-' || room[y][x] == '|' || room[y][x] == 'O' );
}
inline bool isValid(int x,int y) { return 0 <= x && x < W && 0 <= y && y < H; }
inline bool validMove(int x,int y,int dir) {
  if( room[y][x] == '#' || room[y][x] == '*' || room[y][x] == 'S' || room[y][x] == 'L' || room[y][x] == 'D') return false;
  if( isMirror(x,y) ) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if( !isValid(nx,ny) ) return false;
    if( room[ny][nx] != '.' ) return false;
  }
  return true;
}

void UruruBeam(int sp,int sp_dir){
  rep(i,H) rep(j,W) polluted_room[i][j] = false;
  deque<ii> deq;
  deq.push_back(ii(sp,sp_dir));
  polluted_room[sp/W][sp%W] = true;
  set<ii> S;
  S.insert(ii(sp,sp_dir));
  while( !deq.empty() ){
    ii tmp = deq.front(); deq.pop_front();
    int x = tmp.first % W, y = tmp.first / W, dir = tmp.second;

    while( 1 ){
      x += dx8[dir], y += dy8[dir];

      if( !isValid(x,y) ) break;
      polluted_room[y][x] = true;
      if( room[y][x] == '#' || room[y][x] == '*' || room[y][x] == 'D' || room[y][x] == 'L' ) break;
      if( room[y][x] == 'S' ) {
        if( dir & 1 ) polluted_room[y][x] = false;
        break;
      }

      if( room[y][x] == '/' ) {
        if( dir == 1 || dir == 5 ) break;
        int next_dir = -1;
        if( dir == 0 ) next_dir = 2;
        else if( dir == 2 ) next_dir = 0;
        else if( dir == 3 ) next_dir = 7;
        else if( dir == 4 ) next_dir = 6;
        else if( dir == 6 ) next_dir = 4;
        ii next = ii(x+y*W,next_dir);
        if( S.count(next) ) break;
        S.insert(next);
        deq.push_back(next);
        break;
      } else if( room[y][x] == '\\' ) {
        if( dir == 3 || dir == 7 ) break;
        int next_dir = -1;
        if( dir == 0 ) next_dir = 6;
        else if( dir == 1 ) next_dir = 5;
        else if( dir == 2 ) next_dir = 4;
        else if( dir == 4 ) next_dir = 2;
        else if( dir == 5 ) next_dir = 1;
        else if( dir == 6 ) next_dir = 0;
        ii next = ii(x+y*W,next_dir);
        if( S.count(next) ) break;
        S.insert(next);
        deq.push_back(next);
        break;
      } else if( room[y][x] == '-' ) {
        if( dir == 2 || dir == 6 ) break;
        int next_dir = -1;
        if( dir == 0 ) next_dir = 4;
        else if( dir == 1 ) next_dir = 3;
        else if( dir == 3 ) next_dir = 1;
        else if( dir == 4 ) next_dir = 0;
        else if( dir == 5 ) next_dir = 7;
        else if( dir == 7 ) next_dir = 5;
        ii next = ii(x+y*W,next_dir);
        if( S.count(next) ) break;
        S.insert(next);
        deq.push_back(next);
        break;
      } else if( room[y][x] == '|' ) {
        if( dir == 0 || dir == 4 ) break;
        int next_dir = -1;
        if( dir == 1 ) next_dir = 7;
        else if( dir == 2 ) next_dir = 6;
        else if( dir == 3 ) next_dir = 5;
        else if( dir == 5 ) next_dir = 3;
        else if( dir == 6 ) next_dir = 2;
        else if( dir == 7 ) next_dir = 1;
        ii next = ii(x+y*W,next_dir);
        if( S.count(next) ) break;
        S.insert(next);
        deq.push_back(next);
        break;
      } else if( room[y][x] == 'O' ) {
        ii next[2] = {ii(x+y*W,-1),ii(x+y*W,-1)};
        if( dir == 0 ) next[0].second = 1, next[1].second = 7;
        else if( dir == 1 ) next[0].second = 0, next[1].second = 2;
        else if( dir == 2 ) next[0].second = 1, next[1].second = 3;
        else if( dir == 3 ) next[0].second = 2, next[1].second = 4;
        else if( dir == 4 ) next[0].second = 3, next[1].second = 5;
        else if( dir == 5 ) next[0].second = 4, next[1].second = 6;
        else if( dir == 6 ) next[0].second = 7, next[1].second = 5;
        else if( dir == 7 ) next[0].second = 0, next[1].second = 6;
        rep(_i,2) {
          if( !S.count(next[_i]) ) {
            S.insert(next[_i]);
            deq.push_back(next[_i]);
          }
        }
        break;
      }
    }
  }
}

//現状でゴールに到達可能か判定, この関数を呼ぶ前にうるるビームを発射してpolluted_roomを作成しておくこと
bool solved(int sp){
  rep(i,(int)statue.size()) if( !polluted_room[statue[i]/W][statue[i]%W] ) return false;
  rep(i,H) rep(j,W) visited[i][j] = false;
  deque<int> deq;
  deq.push_back(sp);
  visited[sp/W][sp%W] = true;
  while( !deq.empty() ){
    int cur = deq.front(); deq.pop_front();
    if( polluted_room[cur/W][cur%W] ) continue;
    if( room[cur/W][cur%W] == 'D' ) return true;
    rep(i,4) {
      int nx = cur % W + dx[i], ny = cur / W + dy[i];
      if( !isValid(nx,ny) ) continue;
      if( !( room[ny][nx] == '.' || room[ny][nx] == 'D' ) ) continue; // 鏡を動かしてゴールできる場合はまた別、再帰でみつけるべし
      if( polluted_room[ny][nx] || visited[ny][nx] ) continue;
      visited[ny][nx] = true;
      deq.push_back(nx+ny*W);
    }
  }
  return false;
}



typedef pair<int,vector<int> > ivi;
set<ivi> S;
bool BackTracking(int cur,int prev,deque<int> &deq){

  if( !deq.empty() ) sort(deq.begin(),deq.end());
  vector<int> tmper;
  rep(i,deq.size()) tmper.push_back(deq[i]*1000+room[deq[i]/W][deq[i]%W]);
  if( S.count(ivi(cur,tmper)) ) return false;
  S.insert(ivi(cur,tmper));

  UruruBeam(LP,LP_dir);

  if( polluted_room[cur/W][cur%W] ) return false; // dead
  if( solved(cur) ) return true;
  rep(i,4){
    if( prev == (i+2) % 4 ) continue;
    int nx = cur % W + dx[i], ny = cur / W + dy[i];
    if( !isValid(nx,ny) ) continue;
    if( !validMove(nx,ny,i) ) continue;
    bool mirror = false;
    int new_one = -1;
    if( isMirror(nx,ny) ) {
      rep(j,deq.size()) if( deq[j]%W == nx && deq[j]/W == ny ) {
        new_one = j;
        break;
      }
      if( new_one == -1 && deq.size() == 2 ) continue;

      assert(room[ny+dy[i]][nx+dx[i]] == '.');
      if( new_one == -1 ) deq.push_back((nx+dx[i])+(ny+dy[i])*W);
      else                deq[new_one] = (nx+dx[i])+(ny+dy[i])*W;
      room[ny+dy[i]][nx+dx[i]] = room[ny][nx]; 
      room[ny][nx] = '.';
      mirror = true;
      UruruBeam(LP,LP_dir);
      if( polluted_room[ny][nx] ) goto Skip;
    } 
    if( !mirror && polluted_room[ny][nx] ) continue;
    if( BackTracking(nx+ny*W,(mirror?-1:i),deq) ) return true;

  Skip:;
    if( mirror ) {
      assert( isMirror(nx+dx[i],ny+dy[i]) );
      room[ny][nx] = room[ny+dy[i]][nx+dx[i]];
      room[ny+dy[i]][nx+dx[i]] = '.';
      if( new_one == -1 ) {
        rep(j,deq.size()) if( deq[j] == (nx+dx[i])+(ny+dy[i])*W ) {
          deq.erase(deq.begin()+j);
          break;
        }
      } else {
        rep(j,deq.size()) if( deq[j] == (nx+dx[i])+(ny+dy[i])*W ) {
          deq[j] = nx + ny * W;
          break;
        }
      }
    }
  }
  return false;
}

int main(){
  LP = LP_dir = -1;
  int sp = -1;
  cin >> W >> H;
  rep(i,H) rep(j,W) {
    cin >> room[i][j];
    if( room[i][j] == '@' ) sp = j + i * W,room[i][j] = '.';
    if( room[i][j] == 'L' ) { assert( LP == -1); LP = j + i * W; }
    if( room[i][j] == 'S' ) statue.push_back(j+i*W);
  }
  for(int k=0;k<8;k+=2) {
    int nx = LP%W + dx8[k], ny = LP/W + dy8[k];
    if( !isValid(nx,ny) ) continue;
    if( nx == 0 || ny == 0 || nx == W-1 || ny == H-1 ) continue;
    LP_dir = k;
  }

  UruruBeam(LP,LP_dir);

  if( polluted_room[sp/W][sp%W] ) { puts("No"); return 0; }
  if( solved(sp) ) { puts("Yes"); return 0; }
  deque<int> deq;
  puts(BackTracking(sp,-1,deq)?"Yes":"No");
  return 0;
}