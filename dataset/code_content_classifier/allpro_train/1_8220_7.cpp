#include<bits/stdc++.h>
 
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
 
using namespace std;
 
struct Edge { int dst,w; };
 
const int MAX = 110;
int V,E,sp,ep,iHIT;
vector<Edge> G[MAX];
int maxi[MAX];
 
 
void compute(){
  bool update = true;
  rep(i,V) maxi[i] = 0;
  vector<int> gotoMaxi,candidate;
  gotoMaxi.push_back(sp);
  while( update ) {
    update = false;
    rep(i,(int)gotoMaxi.size()) maxi[gotoMaxi[i]] = iHIT;
    gotoMaxi.clear();
    candidate.clear();

    rep(i,V*3+1) {
      rep(j,V) if( j != ep && maxi[j] ) {
        rep(k,(int)G[j].size()) {
          Edge &e = G[j][k];
          if( maxi[e.dst] < min(maxi[j]+e.w,iHIT) ) {
            update = true;
            maxi[e.dst] = min(maxi[j]+e.w,iHIT);
            if( i == V*3 ) candidate.push_back(e.dst);
          }
        }
      }
    }
    
    //cout<<endl;
    //for(int i=0;i<(int)candidate.size();i++)cout<<candidate[i]<<endl;
    
    int maxValue = 0;
    rep(i,(int)candidate.size()) maxValue = max(maxValue,maxi[candidate[i]]);
    if( maxValue ) rep(i,(int)candidate.size()){
       
        if( maxValue == maxi[candidate[i]] ){
          
          gotoMaxi.push_back(candidate[i]);
        }
      }
    
    
  }
 
  /*
    
  */
 
 
  if( maxi[ep] == 0 ) puts("GAME OVER");
  else                cout << maxi[ep] << endl;
 
}
 
int main(){
  int CNT = 1;
  while( cin >> V >> E, V | E ){
    rep(i,V) G[i].clear();
    rep(i,E){
      int s,t,c;
      cin >> s >> t >> c;
      G[s].push_back((Edge){t,c});      
    }
    cin >> sp >> ep >> iHIT;
    cout << "Case " << CNT++ << ": ";
    compute();
  }
  return 0;
}