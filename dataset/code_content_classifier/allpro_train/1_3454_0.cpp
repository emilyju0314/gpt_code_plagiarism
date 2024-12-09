#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<ctime>
#include<cstdio>
#include<map>
#include<set>

using namespace std;

class Dice{
public:
   int x,y;
   int C[3];
   Dice(int c0,int c1,int c2,int _x,int _y){
      C[0] = c0;
      C[1] = c1;
      C[2] = c2;
      x = _x;
      y = _y;
   };
   Dice(){};
   void rotate_left(){
      swap(C[0],C[2]);
      C[2] = 7 - C[2];
   }
   void rotate_right(){
      swap(C[0],C[2]);
      C[0] = 7 - C[0];
   }
   void rotate_front(){
      swap(C[0],C[1]);
      C[0] = 7 - C[0];
   }
   void rotate_back(){
      swap(C[0],C[1]);
      C[1] = 7 - C[1];
   }
   void rotate(){
      swap(C[1],C[2]);
      C[1] = 7 - C[1];
   }
   bool operator < (const Dice &d)const {
      return false;
   }
};

class Status{
public:
   int state[3],x[3],y[3];
   Status(){};
   Status(int s0,int y0,int x0,int s1,int y1,int x1,int s2,int y2,int x2){
      state[0] = s0;
      x[0] = x0;
      y[0] = y0;
      state[1] = s1;
      x[1] = x1;
      y[1] = y1;
      state[2] = s2;
      x[2] = x2;
      y[2] = y2;
   };
   bool operator < (const Status &s)const {
      for(int i = 0 ; i < 3 ; i++){
	 if(state[i] != s.state[i])return state[i] < s.state[i];
	 if(x[i] != s.x[i])return x[i] < s.x[i];
	 if(y[i] != s.y[i])return y[i] < s.y[i];
      }
      return false;
   }
};

Dice allState[24];
int indexState[7][7][7];

void createAll(){
   Dice dice(1,2,4,0,0);
   for(int i = 0 ; i < 6 ; i++){
      for(int j = 0 ; j < 4 ; j++){
         allState[i*4+j] = dice;
         indexState[dice.C[0]][dice.C[1]][dice.C[2]] = i*4+j;
         dice.rotate();
      }
      if(i%2)dice.rotate_front();
      else dice.rotate_right();
   }
}

int H,W;
const int MAX = 20;
const int INF = 1e8;
char data[MAX][MAX];
int h[3][24][MAX][MAX];
vector<Dice>ini;
void init(){
   ini.clear();
   for(int i = 0 ; i < 3 ; i++){
      for(int j = 0 ; j < 24 ; j++){
         for(int k = 0 ; k < MAX ; k++){
	    for(int l = 0 ; l < MAX ; l++){
	       h[i][j][k][l] = INF;
	    }
         }
      }
   }
}

typedef pair<int,vector<Dice> > PP;
typedef pair<int,PP > PP2;
typedef pair<int,int>P;
typedef pair<int,P>P2;

void input(){
   for(int i = 0 ; i < H ; i++){
      for(int j = 0 ; j < W ; j++){
         cin >> data[i][j];
         if(data[i][j] == 'o'){
            ini.push_back(Dice(1,2,4,j,i));
         }
      }
   }
}

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

bool isOK(vector<Dice>vec){
   for(int i = 0 ; i < 3 ; i++){
      if(!isdigit(data[vec[i].y][vec[i].x]))return false;
      if(vec[i].C[0] != data[vec[i].y][vec[i].x] - '0')return false;
   }
   return true;
}

int heuristic(int cnt,vector<Dice> vec){
   int res = INF;
   int index[3] = {0,1,2};

   int s[3];
   s[0] = indexState[vec[0].C[0]][vec[0].C[1]][vec[0].C[2]];
   s[1] = indexState[vec[1].C[0]][vec[1].C[1]][vec[1].C[2]];
   s[2] = indexState[vec[2].C[0]][vec[2].C[1]][vec[2].C[2]];

   do{
      res = min(res,cnt + h[index[0]][s[0]][vec[0].y][vec[0].x] + h[index[1]][s[1]][vec[1].y][vec[1].x] + h[index[2]][s[2]][vec[2].y][vec[2].x]);
   }while(next_permutation(index,index + 3));

   return res;
}

bool check(P p){
   if(!(0 <= p.first && p.first < H))return true;
   if(!(0 <= p.second && p.second < W))return true;
   return false;
}

void solve(){
   
   priority_queue<PP2,vector<PP2>,greater<PP2> >que;
   vector<Dice>vec;
   
   que.push(PP2(heuristic(0,ini),PP(0,ini)));
   map<Status,int>vis;

   vis[Status(indexState[ini[0].C[0]][ini[0].C[1]][ini[0].C[2]],ini[0].y,ini[0].x,
	      indexState[ini[1].C[0]][ini[1].C[1]][ini[1].C[2]],ini[1].y,ini[1].x,
	      indexState[ini[2].C[0]][ini[2].C[1]][ini[2].C[2]],ini[2].y,ini[2].x)] = 0;

      
   while(que.size()){
      PP2 pp2 = que.top(); que.pop();
      
      int cnt = pp2.second.first * -1;
      vec = pp2.second.second;

      int H = pp2.first;

      for(int i = 0 ; i < 3 ; i++){
         for(int j = 0 ; j < 4 ; j++){
            vector<Dice> nvec = vec;	    
            
            nvec[i].x = nvec[i].x + dx[j];
            nvec[i].y = nvec[i].y + dy[j];
            
            switch(j){
               case 0:
                  nvec[i].rotate_back();
                  break;
               case 1:
                  nvec[i].rotate_right();
                  break;
               case 2:
                  nvec[i].rotate_front();
                  break;
               case 3:
                  nvec[i].rotate_left();
                  break;
            }
            
            if(data[nvec[i].y][nvec[i].x] == 'x')continue;
	    if(check(P(nvec[i].y,nvec[i].x)))continue;
	    bool iscollide = false;
	    for(int k = 0 ; k < 3; k++){
	       if(i == k)continue;
	       if(nvec[i].y == nvec[k].y && nvec[i].x == nvec[k].x)iscollide = true;
	    }

	    if(iscollide)continue;
	    if(isOK(nvec)){
	       cout << cnt+1 << endl;
	       return;
	    }

	    Status nstatus = Status(indexState[nvec[0].C[0]][nvec[0].C[1]][nvec[0].C[2]],nvec[0].y,nvec[0].x,
				    indexState[nvec[1].C[0]][nvec[1].C[1]][nvec[1].C[2]],nvec[1].y,nvec[1].x,
				    indexState[nvec[2].C[0]][nvec[2].C[1]][nvec[2].C[2]],nvec[2].y,nvec[2].x);

	    if(vis.find(nstatus) == vis.end() || vis[nstatus] > cnt){
	       vis[nstatus] = cnt;
	       que.push(PP2(heuristic(cnt+1,nvec),PP((cnt+1)*-1,nvec)));
	    }
         }
      }
   }
   cout << "error" << endl;//
}


typedef pair<int,Dice> P3;


void bfs(P p,int id){

   queue<P3>que;
   Dice dice;

   for(int i = 0 ; i < 24 ; i++){
      dice =  allState[i];
      if(data[p.first][p.second] - '0' == dice.C[0]){
	 dice.y = p.first;
	 dice.x = p.second;
	 h[id][indexState[dice.C[0]][dice.C[1]][dice.C[2]]][dice.y][dice.x] = 0;
	 que.push(P3(0,dice));
      }
   }

   while(que.size()){
      P3 p3 = que.front(); que.pop();
      int cnt = p3.first;
      dice = p3.second;
      for(int i = 0 ; i < 4 ; i++){      
	 Dice ndice = dice;
	 ndice.x += dx[i];
	 ndice.y += dy[i];

	 switch(i){
	    case 0:
	       ndice.rotate_back();
	       break;
	    case 1:
	       ndice.rotate_right();
	       break;
	    case 2:
	       ndice.rotate_front();
	       break;
	    case 3:
	       ndice.rotate_left();
	       break;
	 }

	 if(check(P(ndice.y,ndice.x)))continue;
         if(data[ndice.y][ndice.x] == 'x')continue;
	 int ns = indexState[ndice.C[0]][ndice.C[1]][ndice.C[2]];
         if(h[id][ns][ndice.y][ndice.x] == INF){
            h[id][ns][ndice.y][ndice.x] = cnt+1;
            que.push(P3(cnt+1,ndice));
         }
      }
   }
}

int main(){
   createAll();
   int cnt = 1;
   cin >> H >> W;
   init();
   input();
   int id = 0;
   for(int i = 0 ; i < H ; i++){
     for(int j = 0 ; j < W ; j++){
       if(isdigit(data[i][j]))bfs(P(i,j),id++);
     }
   }
   solve();
   return 0;
}