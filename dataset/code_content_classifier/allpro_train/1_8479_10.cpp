#include <bits/stdc++.h>
#define N (1<<20)
using namespace std;
typedef long long ll;
string str;
int bit[N+1],n;
int a[N];

int sum(int i){
  int res=0;
  while(i>0){
    res+=bit[i];
    i-=i&-i;
  }
  return res;
}

void add(int i,int x){
  while(i<=n){
    bit[i]+=x;
    i+=i&-i;
  }
}

ll solve(){
  n=str.size();
  int cnt[30]={},cnt2[30]={};
  for(int i=0;i<n;i++)cnt[str[i]-'a']++;
  for(int i=0;i<30;i++)if(cnt[i]%2)return -1;
  
  int A=0;
  stack <int> stk[30];
  
  for(int i=0;i<n;i++){
    int idx=str[i]-'a';
    if(cnt[idx]/2>cnt2[idx]){
      stk[idx].push(A);
      A++;
      cnt2[idx]++;
      a[i]=A;
    }
    else {
      a[i]=n-stk[idx].top();
      stk[idx].pop();
    }
  }

  ll ans=0;
  for(int j=0;j<n;j++){
    ans+=j-sum(a[j]);
    add(a[j],1);
  }
  return ans;
}


int main(){
  cin>>str;
  cout <<solve()<<endl;  
  return 0;
}