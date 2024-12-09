#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cm[51][51];
ll comb(ll n,ll r){
  if(cm[n][r]!=-1) return cm[n][r];
  if(r==0||r==n) return cm[n][r]=1;
  return cm[n][r]=(comb(n-1,r-1)+comb(n-1,r));
}
int main(){
  ll n,a,b,max_n=0,cnt=0,tmp_num,bc,ac;
  cin >> n >> a >> b;
  vector<ll> v(n);
  for(int i=0;i<=50;i++){
    for(int j=0;j<=50;j++){
      cm[i][j]=-1;
    }
  }
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  sort(v.begin(),v.end(),greater<ll>());
  for(int i=0;i<a;i++){
    max_n+=v[i];
  }
  tmp_num=max_n;
  tmp_num-=v[a-1];
  printf("%.7lf\n",(double)max_n/a);
  for(int i=0;i<=b-a;i++){
    tmp_num+=v[a+i-1];
    if(tmp_num*a==max_n*(a+i)){
      bc=ac=0;
      for(int k=0;k<n;k++){
        if(v[a+i-1]==v[k]){
          if(k<=a+i-1)bc++;
          else ac++;
        }
      }
      cnt+=comb(ac+bc,ac);
    }
  }
  cout << cnt << endl;
}
