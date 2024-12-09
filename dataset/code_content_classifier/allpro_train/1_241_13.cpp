#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

int main() {
  int n;
  cin>>n;
  REP(i,n){
    string cmd;
    cin>>cmd;
    string str;
    cin>>str;
    reverse(begin(cmd),end(cmd));
    for(char c:cmd){
      switch(c){
        case 'C': {
          string body=str.substr(1);
          string head=str.substr(0,1);
          str = body + head;
          break;
        }
        case 'J': {
          string body=str.substr(0,str.size()-1);
          string head=str.substr(str.size()-1);
          str = head + body;
          break;
        }
        case 'E': {
          int mid=str.size()/2;
          string fwd=str.substr(0,mid);
          string bwd=str.substr(str.size()-mid);
          if((str.size()%2)==1){
            str=bwd+str[mid]+fwd;
          }else{
            str=bwd+fwd;
          }
          break;
        }
        case 'A': {
          reverse(begin(str),end(str));
          break;
        }
        case 'M': {
          for(char& d:str){
            if('0' <= d && d < '9')
              ++d;
            else if(d == '9')
              d = '0';
          }
          break;
        }
        case 'P': {
          for(char& c:str){
            if('0' < c && c <= '9')
              --c;
            else if(c == '0')
              c = '9';
          }
          break;
        }
      }
    }
    cout<<str<<endl;
  }
  return 0;
}