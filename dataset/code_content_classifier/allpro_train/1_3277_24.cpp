#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (n) ; ++i)
int n,ANS,vc[20];

void dfs(int rec,int now){
  if(now == n){
    ANS = min(ANS,abs(rec));
    return;
  }
  dfs(rec+vc[now],now+1);
  dfs(rec-vc[now],now+1);
}

int main(){
  while(cin >> n , n){
    ANS = 100000000;
    rep(i,n) cin >> vc[i];
    dfs(0,0);
    cout << ANS << endl;
  }
}