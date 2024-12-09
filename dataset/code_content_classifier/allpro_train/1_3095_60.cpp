#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m; cin>>n>>m;
  vector<int> p(m), y(m);
  for(int i=0; i<m; ++i){cin>>p[i]>>y[i]; --p[i];}

  vector<vector<int>> val(n);
  for(int i=0; i<m; ++i)val[p[i]].push_back(y[i]);

  for(int i=0; i<n; ++i)sort(val[i].begin(), val[i].end());

  for(int i=0; i<m; ++i){
    int x=p[i];
    cout<<setfill('0')<<right<<setw(6)<<x+1;

    int id=lower_bound(val[x].begin(), val[x].end(), y[i])-val[x].begin();
    cout<<setfill('0')<<right<<setw(6)<<id+1<<endl;
  }
  
}
