#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

void solve(){
}

int main(){
  int n,m;

  while(cin>>n>>m,n||m){
    int s[m];
    rep(i,m){
      cin>>s[i];
    }

    bool flg = true;
    rep(i,n){
      rep(j,m){
        int x;
        cin>>x;
        s[j] -= x;
        if(s[j] < 0) flg = false;
      }
    }
    cout<<(flg ? "Yes" : "No")<<endl;
  }
}