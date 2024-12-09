#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,cnt=1,sum=0;
  cin >> n;
  long long a[n],ans=n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a,a+n);
  for(int i=0;i<n-1;i++){
    sum+=a[i];
    if(a[i+1]/sum<2 or (a[i+1]/sum==2 and a[i+1]%sum==0)){
      cnt++;
    }else{
      ans-=cnt;
      cnt=1;
    }
  }
  cout << ans << endl;
  return 0;
}