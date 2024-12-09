#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#define pb push_back

using namespace std;

string s;
int ima;

int sol(){
  ima++;
  if(s[ima]!='['&&s[ima]!=']'){
    int tmp;
    tmp=s[ima]-'0';ima++;
    while(s[ima]!='['&&s[ima]!=']'){
      tmp=tmp*10+s[ima++]-'0';
    }
    ima++;
    return tmp/2+1;
  }

  vector<int> a;
  while(s[ima]!=']'){
    a.pb(sol());
  }
  sort(a.begin(),a.end());
  int res=0;
  for(int i=0;i<a.size()/2+1;i++) res+=a[i];
  ima++;
  return res;
}

int main(){
  int n;
  int i,j,k;
  int tmp;

  cin>>n;
  while(n--){
    cin>>s;
    ima=0;
    cout<<sol()<<endl;
  }
  return 0;
}