#include<iostream>
#include<algorithm>
using namespace std;
bool dp[1000001];
bool isprime(int& x){
  for(int i = 2 ; i * i <= x ; i++ ) if( x % i == 0) return true;
  return x == 1;
}
int solve(int i){
  while(true){ if(dp[i] && !isprime(i)) return i; i--; }
}
int main(){
  int n,x,data[30],ans; dp[0] = true;
  while(cin >> n >> x , n){
    for(int i = 1 ; i <= x ; i++ ) dp[i] = false;
    for(int i = 0 ; i < n ; i++ ) cin >> data[i];
    for(int i = 0 ; i <= x ; i++ ){
      if(dp[i]) for(int j = 0 ; j < n ; j++ )
        if(i + data[j] <= x) dp[i+data[j]] = true;
    }
    if(ans = solve(x)) cout << ans << endl;
    else cout << "NA" << endl;
  }
}