#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>  
using namespace std;

int n;
int mas[101][101];
int dp[101][101];

int rec(int i,int j){
  if(i == n) return 0;
  if(j < 0 || mas[i][j] == -1) return -(2 << 26);
  if(dp[i][j]) return dp[i][j];
  int res = 0;
  if(i < n/2) res = max(rec(i+1,j)+mas[i][j],rec(i+1,j+1)+mas[i][j]);
  else if(i >= n/2) res = max(rec(i+1,j-1)+mas[i][j],rec(i+1,j)+mas[i][j]);
  return dp[i][j] = res;
}

int main(){
  memset(mas,-1,sizeof(mas));
  for(int i=0;;i++){
    stringstream ss;  string s; 
    getline(cin,s);
    n = i;
    if(s.size() == 0) break;
    ss << s;
    for(int j=0;;j++){
      char tr; int fig;
      ss >> fig;  mas[i][j] = fig;
      if(ss.peek() == -1) break;
      ss >> tr;
    }
  }
  cout << rec(0,0) << endl;
}