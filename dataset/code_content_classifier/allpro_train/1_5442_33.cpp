#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin >> n;

  vector<int> t(n);
  int t_max = 0;
  for(int i = 0; i < n; i++){
    cin >> t[i];
    t_max = max(t[i],t_max);
  }

  vector<int> vec(10001);
  for(int i = 1; i <= t_max; i++){
    if(t_max%i == 0) vec.push_back(i);
  }

  int ans = 0;
  for(int i = 0; i < n; i++){
    int j = 0;
    while(vec[j] < t[i]) j++;
    ans += vec[j] - t[i];
  }
  cout << ans << endl;

	return 0;
}

