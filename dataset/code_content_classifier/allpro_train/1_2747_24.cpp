#include <bits/stdc++.h>
using namespace std;

int main() {
  long ans,a,n,m,t;
  cin >> n >> m;
  priority_queue<int> que;
  for(int i=0 ;i<n ;i++){
    cin >> a;
    que.push(a);
  }
  for(int i=0 ;i<m ;i++){
    t = que.top();
    que.pop();
    que.push(t/2);
  }
  while(!que.empty()){
    ans += que.top();
    que.pop();
  }
  cout << ans << endl;

}