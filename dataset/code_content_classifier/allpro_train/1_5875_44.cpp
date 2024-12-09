#include <sstream>
#include <set>
#include <iostream>
#include <algorithm>
#include <queue>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#define f first
#define s second
#define mp make_pair

using namespace std;

struct rule{
  int permit;
  string from;
  string to;

  rule(string p, string f, string t){
    if(p == "permit") permit = 1;
    else permit = 0;
    from = f;
    to = t;
  }
};

bool match(string s, string t){
  REP(i,s.size()){
    if(s[i] == '?' || t[i] == '?') continue;
    if(s[i] != t[i]) return false;
  }
  return true;
}

int main(){
  int n, m;
  while(cin >> n >> m, n + m){
    vector<rule> r;
    REP(i,n){
      string p, f, t;
      cin >> p >> f >> t;
      r.push_back(rule(p, f, t));
    }

    reverse(r.begin(), r.end());

    vector<string> ans;
    REP(i,m){
      string f, t, mes;
      cin >> f >> t >> mes;

      REP(j,n){
	if(match(f, r[j].from) && match(t, r[j].to)){
	  if(r[j].permit){
	    stringstream ss;
	    ss << f << " " << t << " " << mes;
	    ans.push_back(ss.str());
	  }
	  break;
	}
      }
    }

    cout << ans.size() << endl;
    REP(i,ans.size()) cout << ans[i] << endl;
  }
  return 0;
}