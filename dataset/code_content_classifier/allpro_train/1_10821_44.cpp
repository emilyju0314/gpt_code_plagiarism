#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;

ulli pow(int n, int p){
  ulli res = 1;
  for (int i = 0; i < p; i++) {
    res *= n;
    if(res > 1e9) throw "error";
  }
  return res;
}


int main(int argc, char *argv[]){
  int n, t;
  string s;
  cin >> n >> t >> s;
  vector<int> p;
  for (int i = 2; i < s.length(); i+=4) {
    char tmp = s[i];
    p.push_back(atoi(&tmp));
  }
  ulli ans = 0;

  for (int i = 0; i < p.size(); i++) {
    try{
      ans += pow(n, p[i])*t;
      if(ans > 1e9)throw "error";
    }catch(const char* s){
      std::cout << "TLE" << std::endl;
      return 0;
    }
  }
  std::cout << ans << std::endl;

  return 0;
}