#include <iostream>
#include <set>
#include <string>
#include <cstring>
using namespace std;

int t[26][26];

//ノードidからいくつのノードに移動可能か
//すでに探索済みのノードは通らない
int reachableNode(int id,bool *used){
  int res = 1;

  used[id] = true;
  for(int i=0;i<26;i++){
    if(t[id][i] > 0 && !used[i]){
      res += reachableNode(i,used);
    }
  }

  return res;
}

int main(void){
  int n;

  while(cin>>n && n){
    string s;
    int from,to;
    set<int> ap;

    memset(t,0,sizeof(t));

    for(int i=0;i<n;i++){
      cin>>s;
      from = s[0] - 'a';
      to = s[s.size()-1] - 'a';

      //自己ループ以外の辺はカウント
      if(from != to){
        t[from][to]++;
      }
      ap.insert(from);
      ap.insert(to);
    }

    //森が一つだけであるかの確認
    bool used[26];
    memset(used,0,sizeof(used));
    int count = reachableNode(from,used);
    if(count != ap.size()){
      cout<<"NG\n";
      continue;
    }

    //入次数と出次数が同じかどうかの確認
    set<int>::iterator i = ap.begin();
    for(;i!=ap.end();i++){
      int in=0,out=0;
      for(int j=0;j<26;j++){
        in += t[j][*i];
        out += t[*i][j];
      }
      if(in != out) break;
    }

    if(i == ap.end())cout<<"OK\n";
    else cout<<"NG\n";
  }

  return 0;
}