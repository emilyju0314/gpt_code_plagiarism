#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;

int main(){
  int n, m;
  while(cin >> n >> m, n + m){
    vector<int> v(n + m);
    vector<int> d(n + m);

    REP(i,n + m) cin >> v[i];
    sort(v.begin(), v.end());
    adjacent_difference(v.begin(), v.end(), d.begin());
    cout << *max_element(d.begin(), d.end()) << endl;
  }
  return 0;
}