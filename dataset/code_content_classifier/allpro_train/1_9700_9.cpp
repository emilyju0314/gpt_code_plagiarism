#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

int N,H;
string s[110];
int cap[110];

int main(){
  cin >> N >> H;
  rep(i,N) cin >> s[i] >> cap[i];
  double numType = 0;
  double numSucc = 0;
  rep(i,N){
    int cur = 0, miss = 0;
    //char S[20];
    //rep(j,s[i].size()) S[i] = s[i][j];
    //S[s[i].size()] = '\0';
    string S = s[i];
    while( cur < s[i].size() ) {
      //printf("? %s\n", S); fflush(stdout);
      cout << "? " << S << endl; fflush(stdout);
      char c[2];
      scanf(" %s", c);
      ++numType;
      if( tolower(c[0]) == tolower(S[cur]) ) {
	++numSucc;
	S[cur] = '_';
	++cur;
      } else {
	++miss;
      }
      if( miss > cap[i] ) {
	--H;
	break;
      }
    }
    if( H <= 0 ) {
      printf("! Game Over\n"); fflush(stdout);
      return 0;
    } 
  }
  double success_type_rate = numSucc / numType * 100.0;
  success_type_rate *= 10.0;
  success_type_rate = floor(success_type_rate);
success_type_rate /= 10.0;
  printf("! Game Clear %.1lf\n", success_type_rate); fflush(stdout);
  return 0;
}