#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010

/* Aho Corasick */

struct ACNode{
  int val;
  ACNode *next[26], *failure;
  
  ACNode():val(0) { memset(next,0,sizeof(next)); }
  
  void insert(char *s){
    if(!*s){ val++; return; }
    int al = *s-'a';
    if(next[al]==NULL) next[al] = new ACNode;
    next[al]->insert(s+1);
  }

  ACNode *nextNode(char c){
    int al = c - 'a';
    if (next[al]) return next[al];
    return failure == this ? this : failure->nextNode(c);
  }
};

struct AhoCorasick{
  ACNode *node;

  AhoCorasick(){node = new ACNode;}
  
  void insert(char *s) {
    node->insert(s);
  }
  
  void build() {
    queue<ACNode*> que;
    que.push(node);
    node->failure = node;
    
    while(que.size()){
      ACNode *p = que.front();
      que.pop();
      
      for(int i=0;i<26;i++){
        if(p->next[i]){
          ACNode *failure = p->failure;
          while(!failure->next[i] && failure != node){
            failure = failure->failure;
          }
          if (failure->next[i] && failure != p){
            p->next[i]->failure = failure->next[i];
            p->next[i]->val += failure->next[i]->val;
          }else{
            p->next[i]->failure = node;
          }
          que.push(p->next[i]);
        }
      }
    }
  }
};



int main(){
  char s[SIZE], p[SIZE];
  int n;
  AhoCorasick ac;
  
  scanf("%s%d", s, &n);
  
  for(int i=0;i<n;i++){
    scanf("%s", p);
    ac.insert(p);
  }

  ac.build();

  ACNode *now = ac.node;
  int ans = 0;
  for(int i=0;s[i] != '\0';i++){
    now = now->nextNode(s[i]);
    if(now->val){
      ans++;
      now = ac.node;
    }
  }

  printf("%d\n", ans);
  
  return 0;
}


