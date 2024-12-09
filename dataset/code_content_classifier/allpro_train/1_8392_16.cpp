#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int> > V;
void Cut(int,int);
int main(){
  int n,w,d,p,s;
  vector<int> ans;
  while(1){
    cin >> n >> w >> d;
    if(n==0&&w==0&&d==0) break;
    V.push_back(make_pair(0,0));
    V.push_back(make_pair(d,w));
    for(int i=0;i<n;i++){
      cin >> p >> s;
      Cut(p,s);
    }
    for(int i=1;i<V.size();i++) ans.push_back(V[i].first*V[i].second);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
      if(i!=ans.size()-1) cout << ans[i] << ' ';
      else cout << ans[i];
    }
    cout << endl;
    V.clear();
    ans.clear();
  }
  return 0;
}
void Cut(int p,int s){
  int d=V[p].first,w=V[p].second,push1,push2;
  V.erase(V.begin()+p);
  if(s>2*d+2*w) s%=2*d+2*w;
  if(s>w+d) s-=w+d;
  if(0<s&&s<w){
    if(w-s<s) push1=w-s,push2=s;
    else push1=s,push2=w-s;
    V.push_back(make_pair(d,push1));
    V.push_back(make_pair(d,push2));
  }
  else if(w<s&&s<w+d){
    if(w+d-s<s-w) push1=w+d-s,push2=s-w;
    else push1=s-w,push2=w+d-s;
    V.push_back(make_pair(push1,w));
    V.push_back(make_pair(push2,w));
  }
}