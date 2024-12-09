#include <iostream>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;

ull N,V;
ull p[4][1001];

ull solve() {
  unordered_map<ull, ull> c[2];
  for (int i=0; i<2; ++i) {
    for (int j=0; j<N; ++j) {
      for (int k=0; k<N; ++k) {
        ++c[i][p[i*2][j]+p[i*2+1][k]];
        //cout<<i<<" "<<j<<" "<<k<<" "<<p[i*2][j]+p[i*2+1][k]<<" "<<c[i][p[i*2][j]+p[i*2+1][k]]<<endl;
      }
    }
  }
  ull ans = 0;
  for(unordered_map<ull, ull>::const_iterator it = c[0].begin(); it != c[0].end(); ++it) {
    if (V > it->first) {
      ans += (it->second)*c[1][V-it->first];
    }
  }
  return ans;
}

int main() {
  cin>>N>>V;
  for (int i=0; i<4; ++i) {
    for (int j=0; j<N; ++j) {
      cin>>p[i][j];
    }
  }
  cout<<solve()<<endl;
  return 0;
}
