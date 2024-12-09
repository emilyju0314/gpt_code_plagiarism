#include<bits/stdc++.h>
using namespace std;
int n;
string s;

int check(int m){
  int mini=1e9;
  int maxm=-1e9;
  
  for(int i=0;i<m;i++){
    int len=n/m;
    int v=s[i*len+len-1];
    mini=min(mini,v);
    maxm=max(maxm,v);
    for(int j=0;j+1<len;j++){
      if(s[j]!=s[i*len+j])return 1e9;
    }
  }
  return maxm-mini;
}

int solve(){
  if(n==2)return 1e9;
  
  int maxm=-1e9;
  int mini=1e9;
  int i=0;
  while(i<n){
    int num=(s[i]-'0');
    i++;
    if(num==1&&i<n){
      num=num*10+(s[i]-'0');
      i++;
    }
    maxm=max(maxm,num);
    mini=min(mini,num);
  }
  return maxm-mini;
}

int main(){
  cin>>s;
  n=s.size();
  int ans=check(n);
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      ans=min(ans, check(i) );
      ans=min(ans, check(n/i) );
    }
  }

  cout<< min(ans,solve()) <<endl;
  return 0;
}

