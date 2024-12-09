#include <iostream>
#include <algorithm>
#include <string>
#include <map>
 
using namespace std;
 
typedef pair<int, int> P;
typedef long long lli;
 
P factor();
P term();
P exp();
 
bool f;
lli pos;
string data;
 
P factor(){
  if(f) return P(0, 0);
  P res;
  if(data[pos] == '('){
    pos++;
    res = exp();
    pos++;
  }else{
    bool comp = false;
    lli i;
    for(i=pos;i<data.size();i++){
      if(data[i] == 'i'){
        comp = true;
        break;
      }
      if(data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == ')') break;
    }
    if(comp){
      res.first = 0;
      res.second = 1;
      i++;
    }else{
      res.first = atoi(data.substr(pos, i-pos).c_str());
      res.second = 0;
    }
    pos = i;
  }
  if(res.first < -10000 || 10000 < res.first) f = true;
  if(res.second < -10000 || 10000 < res.second) f = true;
  return res;
}
 
P term(){
  if(f) return P(0, 0);
  P res = factor();
  while(data[pos] == '*'){
    char op = data[pos++];
    if(op == '*'){
      P tmp = factor();
      lli a = res.first * tmp.first - res.second * tmp.second;
      lli b = res.first * tmp.second + res.second * tmp.first;
      res.first = a;
      res.second = b;
    }
    if(res.first < -10000 || 10000 < res.first) f = true;
    if(res.second < -10000 || 10000 < res.second) f = true;
    if(f) return res;
  }
  return res;
}
 
P exp(){
  if(f) return P(0, 0);
  P res = term();
  while(data[pos] == '+' || data[pos] == '-'){
    char op = data[pos++];
    if(op == '+'){
      P tmp = term();
      res.first += tmp.first;
      res.second += tmp.second;
    }
    if(op == '-'){
      P tmp = term();
      res.first -= tmp.first;
      res.second -= tmp.second;
    }
    if(res.first < -10000 || 10000 < res.first) f = true;
    if(res.second < -10000 || 10000 < res.second) f = true;
    if(f) return res;
  }
  return res;
}
 
int main(){
  while(cin >> data){
    pos = 0;
    f = false;
    P ans = exp();
    if(f) cout << "overflow" << endl;
    else{
      if(ans.first == 0 && ans.second == 0) cout << 0 << endl;
      else{
        if(ans.first != 0) cout << ans.first;
        if(ans.second == 0) cout << endl;
        else if(ans.second > 0 && ans.first != 0) cout << "+" << ans.second << "i" << endl;
        else cout << ans.second << "i" << endl;
      }
    }
  }
}