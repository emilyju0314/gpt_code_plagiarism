#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<climits>
#include<cassert>
#include<unordered_map>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

string max(string a,string b) {
  if( a.size() == b.size() ) {
    rep(i,(int)a.size()) {
      if( a[i] == b[i] ) continue;
      if( a[i] >  b[i] ) return a;
      else               return b;
    }
    return a;
  } else if( a.size() > b.size() ) {
    return a;
  } else {
    return b;
  }
}

unordered_map<string,string> memo;
string dfs(string s) {
  if( memo.count(s) ) {
    return memo[s];
  }
  bool fin = true;
  rep(i,(int)s.size()) {
    if( s[i] == 'L' || s[i] == 'R' || s[i] == '(' || s[i] == ')' || s[i] == ',' ) {
      fin = false;
      break;
    }
  }
  if( fin ) {
    rep(i,(int)s.size()) {
      if( s[i] == '?' ) s[i] = '9';
    }
    if( s != "0" && s[0] == '0' ) return "";
    return s;
  }
  if( (int)s.size() < 6 ) return "";
  if( !(s[1] == '('||s[1] =='?') || !(s[(int)s.size()-1]==')'||s[(int)s.size()-1]=='?') ) return "";
  string maxi = "";
  if( s[0] == 'L' || s[0] == 'R' || s[0] == '?' ) {
    REP(i,2,(int)s.size()-1) {
      if( s[i] == '?' || s[i] == ',' ) {
	string L = "", R = "";
	REP(j,2,i) L += s[j];
	REP(j,i+1,(int)s.size()-1) R+= s[j];
	string new_L = dfs(L);
	if( new_L.empty() ) continue;
	string new_R = dfs(R);
	if( new_R.empty() ) continue;
	if( s[0] == 'L' || s[0] == 'R' ) {
	  maxi = max(maxi,((s[0]=='L')?new_L:new_R));
	} else {
	  maxi = max(maxi,max(new_L,new_R));
	}
      }
    }
  }
  return memo[s] = maxi;
}

void compute(string s) {
  string answer = dfs(s);
  if( answer.empty() ) puts("invalid");
  else cout << answer << endl;
}

int main() {
  string s;
  cin >> s;
  compute(s);
  return 0;
}