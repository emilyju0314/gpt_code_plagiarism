#include<iostream>
using namespace std;
#define reps(i,b,n) for(int i = b ; i < (int)n ; ++i )
#define rep(i,n) reps(i,0,n)
int main(){
  string str;
  long long f[21]={1},ans,dat[26] = {},sum = 0,cnt = 0;
  cin >> str;
  rep(i,str.size()) dat[str[i]-'a']++;
  rep(i,26) cnt += dat[i] % 2 , dat[i] /= 2 , sum += dat[i];
  if(cnt > 1) cout << 0 << endl;
  else{
    reps(i,1,21) f[i] = f[i-1] * i;
    ans = f[sum];
    rep(i,26) ans /= f[dat[i]];
    cout << ans << endl;
  }
}