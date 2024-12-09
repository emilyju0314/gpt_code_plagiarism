#include <iostream>
#include <set>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
  multiset<int>max;
  int N;
  cin >> N;
  int c;
  for(int i = 1; i <= N; i++){
    int M;
    cin >> M;
    for(int j = 1; j <= M; j++){
      cin >> c;
      max.insert(c);
      if(i < max.size())max.erase(max.begin());
    }
  } 
  unsigned long long ans = 0;
  for(auto it = max.begin(); it != max.end(); it++) ans += *it;
  cout << ans << endl;
}


