#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
vector<int> lazy;
vector<int> ary;
int n;
int right(int k){
  return 2*k+2;
}
int left(int k){
  return 2*k+1;
}
int parent(int k){
  return (k-1)/2;
}
void eval(int k){
  if(lazy[k]==INT_MAX)return;
  if(k<n-1){
    lazy[left(k)]=lazy[right(k)]=lazy[k];
  }
  ary[k]=lazy[k];
  lazy[k]=INT_MAX;
}

void update(int a,int b,int k,int x,int l,int r){
  eval(k);
  if(r<=a||b<=l)return;
  if(a<=l&&r<=b){
    lazy[k]=x;
    eval(k);
  }
  else{
    update(a,b,left(k),x,l,(l+r)/2);
    update(a,b,right(k),x,(l+r)/2,r);
    ary[k] = min(ary[left(k)],ary[right(k)]);
  }
}

int query(int a,int b,int k,int l,int r){
  int res;
  eval(k);
  if(r<=a || b<=l){
    res = INT_MAX;
  }
  else if(a<=l && r<=b)res = ary[k];
  else res = min(query(a,b,left(k),l,(l+r)/2),query(a,b,right(k),(l+r)/2,r));
  return res;
}
void findmin(int a,int b){
    cout<<query(a,b+1,0,0,n)<<endl;
}
int main(){
  int m,q,com,s,t,x,i=0;
  cin>>n>>q;
  while(n>pow(2,i))i++;
  n = pow(2,i);
  m = n*2-1;
  lazy.resize(m+1);
  ary.resize(m+1);
  for(int i=0;i<=m;i++){
    lazy[i] = INT_MAX;
    ary[i] = INT_MAX;
  }
  for(int i=0;i<q;i++){
    cin>>com>>s>>t;
    if(!com){
      cin>>x;
      update(s,t+1,0,x,0,n);
    }
    else
      findmin(s,t);
  }
  return 0;
}

