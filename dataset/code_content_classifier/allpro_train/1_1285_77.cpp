#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
#define M 1000000007
int main(){
  int n,c=0;
  cin>>n;
  vector<int> a(n+1),b(n+1,0),d;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  for(int i=n;i>0;i--){
      int cnt=0;
      for(int j=i;j<=n;j+=i){
        cnt+=b[j];
      }
      if(cnt%2!=a[i]){
        b[i]=1;
        c++;
        d.push_back(i);
      }
  }
  cout<<c<<endl;
  for(int i=c-1;i>=0;i--){
    cout<<d[i]<<" ";
  }
}
