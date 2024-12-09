#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL now,bo,si,count;
  string s;
  while(1){
    cin >> s;
    if(s=="#") return 0;
    now=s.length()-1;
    count=0;
    while(now>=0){
      if(s[now]=='t'){
        now-=4;
      }else{
        now-=5;
      }
      count++;
    }
    now=s.length()-1;
    if(count<=2){
      if(s[now]=='t'){
        bo=90;
        now-=4;
      }else{
        bo=0;
        now-=5;
      }
      while(now>=0){
        if(s[now]=='t'){
          bo+=45;
          now-=4;
        }else{
          bo-=45;
          now-=5;
        }
      }
      cout << bo << endl;
    }else{
      si=1<<(count-2);
      if(s[now]=='t'){
        bo=90*(1<<(count-2));
        now-=4;
      }else{
        bo=0;
        now-=5;
      }
      count--;
      while(now>=0){
        if(s[now]=='t'){
          bo+=45*1<<(count-1);
          now-=4;
        }else{
          bo-=45*(1<<(count-1));
          now-=5;
        }
        count--;
      }
      cout << bo << "/" << si << endl;
    }
  }
  return 0;
}

