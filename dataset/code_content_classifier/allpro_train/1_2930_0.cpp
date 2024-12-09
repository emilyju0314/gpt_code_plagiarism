#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

struct Dice {
   int b,f,l,r,u,d;

   void RollN()
  {
    //  --y;
    int buff = d;
    d = f;
    f = u;
    u = b;
    b = buff;
  }

  void RollS()
  {
    // ++y;
    int buff = d;
    d = b;
    b = u;
    u = f;
    f = buff;
  }

  void RollL() // ----->
  {
    int buff = f;
    f = l;
    l = b;
    b = r;
    r = buff;
  }

  void RollR() // <------
  {
    int buff = f;
    f = r;
    r = b;
    b = l;
    l = buff;
  }

  void RollE() // .o -> o.
  {
    // --x;
    int buff = d;
    d = l;
    l = u;
    u = r;
    r = buff;
  }


  void RollW() // o. -> .o
  {
    //  ++x;
    int buff = d;
    d = r;
    r = u;
    u = l;
    l = buff;
  }

};

//頑張った
void dfs(int x, int y, int f[5][5], Dice &dice, char c, vector<vector<bool>> visited){
   if(x >= 5 || x < 0 || y >= 5 || y < 0 || visited[y][x]){
      return;
   }

   visited[y][x] = true;
   if(f[y][x] == 0){
      return;
   }

   if(c == 'r') dice.RollL();
   if(c == 'l') dice.RollR();
   if(c == 'u') dice.RollS();
   if(c == 'd') dice.RollN();

   dice.b = f[y][x];


   dfs(x+1, y, f, dice, 'r', visited);
   dfs(x-1, y, f, dice, 'l', visited);
   dfs(x, y+1, f, dice, 'd', visited);
   dfs(x, y-1, f, dice, 'u', visited);

   if(c == 'r') dice.RollR();
   if(c == 'l') dice.RollL();
   if(c == 'u') dice.RollN();
   if(c == 'd') dice.RollS();
}

int main(){
   int n; cin>>n;
   while(n--){
      int f[5][5];
      vector<int> nums(7, 0);
      int x, y;
      for(int i=0; i<5; i++){
         for(int j=0; j<5; j++){
            cin>>f[i][j];
            nums[f[i][j]]++;
            if(f[i][j] != 0) x=j,y=i;
         }
      }

      //1-6の出現回数が1ならok
      bool flag = false;
      for(int i=1; i<7; i++){
         if(nums[i] != 1) flag = true;
      }
      if(flag){
         cout << "false" << endl;
         continue;
      }

      Dice dice = {0, 0, 0, 0, 0, 0};
      vector<vector<bool>> visited(5, vector<bool>(5, false));
      dfs(x, y, f, dice, 'b', visited);

      cout << ((dice.b + dice.f == 7 && dice.l+dice.r == 7 && dice.u+dice.d == 7) ? "true" : "false") << endl;
   }
}
