#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
map<string,priority_queue<int> >q;
map<string,int>st;
 
void END(){
  cout<<"No"<<endl;
  exit(0);
}
 
int main(){
  int n,m;
  cin>>n;
  string s[n];
  int D[n];
  r(i,n)cin>>s[i]>>D[i],st[s[i]]++;
  r(i,n){
    q[s[i]].push(D[i]);
  }
  cin>>m;
  string t[m];
  int ans[m];
  r(i,m)cin>>t[m-i-1];
  r(i,m){
    if(q[t[i]].empty())END();
    while(i){
      if(q[t[i]].empty())END();
      if(q[t[i]].top()<ans[i-1])break;
      else q[t[i]].pop();
    }
    int x=q[t[i]].top();
    ans[i]=x;
  }
  cout<<"Yes"<<endl;
}
