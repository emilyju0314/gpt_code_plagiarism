// Deciphering Characters
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <cstring>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PP;

int pic[102][102];
int h, w;

string bfs(queue<PP> que){
  vector<queue<PP> >nexts;
  while(!que.empty()){
    int cost = que.front().first;
    int x = que.front().second.first;
    int y = que.front().second.second;
    //cout << x << " " << y << endl;
    que.pop();
    int dn = 8;
    int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
    int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};
    if(cost % 2 == 0){
      dn = 4;
    }
    for(int i=0;i<dn;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx > h+1 || ny > w+1) continue;
      if(pic[nx][ny] == -1) continue;
      pic[nx][ny] = -1;
      queue<PP> next_que;
      queue<PP> next;
      next_que.push(make_pair(cost + 1, make_pair(nx, ny)));
      next.push(make_pair(cost + 1, make_pair(nx, ny)));
      while(!next_que.empty()){
	int acost = next_que.front().first;
        int ax = next_que.front().second.first;
        int ay = next_que.front().second.second;
	//	cout << "ax " << ax << " " << ay << endl;
	next_que.pop();	
        int adn = 8;
        int adx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
        int ady[8] = {1, 0, -1, 0, 1, -1, -1, 1};
        if(acost % 2 == 0){
          adn = 4;
        }
	
        for(int i=0;i<adn;i++){
          int anx = ax + adx[i];
          int any = ay + ady[i];
	  //cout << "anx " << anx << " " << any << endl;
          if(anx < 0 || any < 0 || anx > h+1 || any > w+1) continue;
          if(pic[anx][any] == -1) continue;
	  if(pic[anx][any] == acost % 2){
	    next_que.push(make_pair(acost, make_pair(anx, any)));
	    next.push(make_pair(acost, make_pair(anx, any)));
	    pic[anx][any] = -1;
	  }
	}
      }
      nexts.push_back(next);
    }
  }
  if(nexts.size() > 0){
    vector<string> ret;
    for(int i=0;i<nexts.size();i++){
      ret.push_back(bfs(nexts[i]));
    }
    sort(ret.begin(), ret.end());
    ostringstream os;
    copy(ret.begin(), ret.end(), ostream_iterator<string>(os));
    return "(" + os.str() + ")";
  }
  return "()";
}

int main(){
  while(1){
    cin >> h >> w;
    if(h == 0 && w == 0) break;
    memset(pic, 0, sizeof(pic));
    for(int i=0;i<h;i++){
      string p;
      cin >> p;
      for(int j=0;j<w;j++){
	pic[i+1][j+1] = p[j] == '#';
      }
    }
    queue<PP> que;
    queue<PP> next;    
    que.push(make_pair(0, make_pair(0, 0)));
    next.push(make_pair(0, make_pair(0, 0)));
    pic[0][0] = -1;
    while(!que.empty()){
      int cost = que.front().first;
      int x = que.front().second.first;
      int y = que.front().second.second;
      que.pop();
      int dx[4] = {0, 1, 0, -1};
      int dy[4] = {1, 0, -1, 0};
      for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx > h+1 || ny > w+1) continue;
        if(pic[nx][ny] == -1) continue;
	  if(pic[nx][ny] == cost % 2){
	    que.push(make_pair(cost, make_pair(nx, ny)));
	    next.push(make_pair(cost, make_pair(nx, ny)));
	    pic[nx][ny] = -1;
	  }
	}
    }
    string pic1 = bfs(next);
    queue<PP>().swap(que);
    queue<PP>().swap(next);
    
    cin >> h >> w;
    memset(pic, 0, sizeof(pic));
    for(int i=0;i<h;i++){
      string p;
      cin >> p;
      for(int j=0;j<w;j++){
	pic[i+1][j+1] = p[j] == '#';
      }
    }
    
    que.push(make_pair(0, make_pair(0, 0)));
    next.push(make_pair(0, make_pair(0, 0)));
    pic[0][0] = -1;
    while(!que.empty()){
      int cost = que.front().first;
      int x = que.front().second.first;
      int y = que.front().second.second;
      que.pop();      
      int dx[4] = {0, 1, 0, -1};
      int dy[4] = {1, 0, -1, 0};
      for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx > h+1 || ny > w+1) continue;
        if(pic[nx][ny] == -1) continue;
	  if(pic[nx][ny] == cost % 2){
	    que.push(make_pair(cost, make_pair(nx, ny)));
	    next.push(make_pair(cost, make_pair(nx, ny)));
	    pic[nx][ny] = -1;
	  }
	}
    }
    string pic2 = bfs(next);
    queue<PP>().swap(que);
    queue<PP>().swap(next);
    //cout << pic1 << endl;
    //cout << pic2 << endl;
    if(pic1 == pic2){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
  }
  return 0;
}

