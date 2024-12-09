#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

/*
  計算量はたかだか2^9
*/
int ans;
void solve(int now,int val,int base,int *a,int *b,int borrow,int k){
  if (k < 0)return;
  if (now == -1){
    ans = max(ans,val);
    return;
  }
  if (a[now]-borrow >= b[now]){
    solve(now-1,val + base * (a[now]-borrow-b[now]   ),base*10,a,b,0,k);
  }else {
    solve(now-1,val + base * (a[now]-borrow+10-b[now]),base*10,a,b,1,k);
    solve(now-1,val + base * (a[now]-borrow+10-b[now]),base*10,a,b,0,k-1);
  }
}

int main(){
  int a,b,k;
  char buf[20];
  int aa[12],ba[12];
  while(cin>>a>>b>>k){
    sprintf(buf,"%d",a);
    int len = strlen(buf);
    rep(i,len)aa[i] = buf[i]-'0';
    sprintf(buf,"%d",b);
    int lenb = strlen(buf);
    rep(i,lenb)ba[i+len-lenb] = buf[i] - '0';
    rep(i,len-lenb)ba[i] = 0;
    ans = 0;
    solve(len-1,0,1,aa,ba,0,k);    
    cout << ans << endl;
  }
  return 0;
}