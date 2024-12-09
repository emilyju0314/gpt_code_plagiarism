#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define DEB 1
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back

pair<string,string> pss[12];
map<string,int> msi;

string subplace(string &s, int i){
  int p = 0;
  string ret = s;
  while( (p=ret.find(pss[i].first,p))!=string::npos ){
    ret.replace(p, pss[i].first.length(), pss[i].second);
    p += pss[i].second.size();
  }
  return ret;
}

int main(){
  int n;
  while(cin>>n,n){
    msi.clear();
    rep(i,n){
      cin >> pss[i].first >> pss[i].second;
    }
    string a,b;
    cin>>a>>b;
    
    int ans = -1;
    queue<pair<string,int> > q;
    q.push(mp(a,0));
    msi[a] = 0;
    while( !q.empty() ){
      string s = q.front().first;
      int c = q.front().second;
      q.pop();
      if( s.length() > 100 )break;
      if( s==b ){
	ans = c;
	break;
      }
      rep(i,n){
	string tmp = subplace(s,i);
	if( msi.find(tmp)==msi.end() ){
	  q.push(mp(tmp,c+1));
	  msi[tmp] = c+1;
	}
      }
    }
    
    printf("%d\n",ans);
  }
  return 0;
}