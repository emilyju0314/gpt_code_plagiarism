#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

#define rep(i, n) for(int i = 0 ; i < n ; i++)

typedef pair<int, int> P;

struct Point{
  int x, y;
  Point(int a, int b){
    x = a, y = b;
  }
};

const int MAX = 510;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

char field[MAX][MAX];
bool found[26];
vector<Point> alpha[26];
int H, W;

bool checkH(int x1, int x2, int y, char c){
  if(x1 > x2) swap(x1, x2);
  for(int j = x1 ; j <= x2 ; j++){
    if(field[y][j] != '.' && field[y][j] != c) return false;
  }
  return true;
}

bool checkW(int y1, int y2, int x, char c){
  if(y1 > y2) swap(y1, y2);
  for(int i = y1 ; i <= y2 ; i++){
    if(field[i][x] != '.' && field[i][x] != c) return false;
  }
  return true;
}

int main(){
  while(cin >> H >> W){
    rep(i, H) cin >> field[i];
    
    memset(alpha, 0, sizeof(alpha));
    memset(found, 0, sizeof(found));
    
    rep(i, H){
      rep(j, W){
	if(isalpha(field[i][j])){
	  int c = field[i][j]-'A';
	  if(!found[c]){
	    found[c] = true;
	    alpha[c].push_back(Point(j, i));
	    //alpha[c].x1 = j, alpha[c].y1 = i;
	  }
	  else{
	    alpha[c].push_back(Point(j, i));
	    //alpha[c].x2 = j, alpha[c].y2 = i;
	  }
	}
      }
    }
    
    vector<Point> cross[26];
    rep(i, 26){
      if(found[i]){
	cross[i].push_back(Point(alpha[i][0].x, alpha[i][1].y));
	cross[i].push_back(Point(alpha[i][1].x, alpha[i][0].y));
	//cross[i].x1 = alpha[i].x1, cross[i].y1 = alpha[i].y2;
	//cross[i].x2 = alpha[i].x2, cross[i].y2 = alpha[i].y1;
      }
    }
    
    rep(i, 26){
      assert(alpha[i].size() == 2 || alpha[i].size() == 0);
    }
    
    rep(i, H){
      rep(j, W){
	rep(k, 4){
	  int nx = j+dx[k], ny = i+dy[k];
	  if(nx < 0 || nx > W || ny < 0 || ny > H) continue;
	  if(field[i][j] == field[ny][nx]) found[field[i][j]-'A'] = false;
	}
      }
    }
    
    int ans = 0;
    for(; ;){
    Start:;
      bool flag = false;
      rep(i, 26){
	if(found[i]){	  
	  int X1 = cross[i][0].x, Y1 = cross[i][0].y, X2 = cross[i][1].x, Y2 = cross[i][1].y;
	  int x1 = alpha[i][0].x, y1 = alpha[i][0].y, x2 = alpha[i][1].x, y2 = alpha[i][1].y;
	  char c = 'A'+i;
	  
	  if(x1 == x2){
	    flag = checkW(y1, y2, x1, c);
	  }
	  else if(y1 == y2){
	    flag = checkH(x1, x2, y1, c);	    
	  }
	  else{
	    if(((checkH(X1, x2, Y1, c) && (checkW(Y1, y1, X1, c)))) ||
	       ((checkH(X2, x1, Y2, c) && (checkW(Y2, y2, X2, c))))){
	      flag = true;
	    }
	  }
	  
	  if(flag){
	    //cout << c << endl;
	    found[i] = false;
	    ans += 2;
	    field[y1][x1] = '.', field[y2][x2] = '.';	    
	    goto Start;
	  }
	  
	}
      }
      if(!flag) break;
    }
    cout << ans << endl;
  }  
  return 0;
}