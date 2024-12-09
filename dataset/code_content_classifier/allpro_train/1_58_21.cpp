#include <bits/stdc++.h>
using namespace std;


void dfs(string S, char max_char, int N){
  if(S.size()==N){
      cout << S << endl;
      return;
  }
  for(char c='a'; c<=max_char; c++){
    dfs(S+c, max_char, N);
  }
  max_char++;
  dfs(S+max_char, max_char, N);
}

int main(){
  int N;
  cin >> N;
  dfs("a", 'a', N);
  return 0;
}
