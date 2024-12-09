#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,double>> graph;

lli n;
graph g;
mad p;

double dist(vdl& a,vdl& b){
  return max(0.0,sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]))-a[2]-b[2]);
}

priority_queue<vdl,vector<vdl>,greater<vdl>> q;
set<lli> used;

int main(){
  vdl s = vdl(3);
  vdl t = vdl(3);
  cin >> s[0] >> s[1]
  >> t[0] >> t[1];
  p.push_back(s);
  p.push_back(t);
  cin >> n;
  for(lli i = 0;i < n;i++){
    vdl q = vdl(3);
    cin >> q[0] >> q[1] >> q[2];
    p.push_back(q);
  }
  for(lli i = 0;i < p.size();i++){
    for(lli j = 0;j < p.size();j++){
      g[i][j] = dist(p[i],p[j]);
    }
  }
  q.push(vdl({0.0,0.0}));
  while(!q.empty()){
    double c = q.top()[0];
    lli p = (lli)(q.top()[1]);
    q.pop();
    if(p == 1){
      cout << setprecision(17);
      cout << c << endl;
      return 0;
    }
    if(used.count(p) != 0) continue;
    used.insert(p);
    for(auto& itr : g[p]){
      if(used.count(itr.first) == 0) q.push(vdl({c+itr.second,(double)itr.first}));
    }
  }

}
