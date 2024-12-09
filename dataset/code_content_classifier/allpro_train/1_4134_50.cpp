#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long ll;

double INF = 1e9;

int main() {
  int n, m; cin >> n >> m; vector<int> v[n]; // tiの方
  double an[n]; fill(an, an+n, INF); an[n-1] = 0;
  for(int i=0; i<m; i++) {
    int a, b; cin >> a >> b; a--; b--;
    v[a].push_back(b);
  }
  double anan = 1e16;
  for(int id=n-2; id>=0; id--){
    fill(an, an+n, INF); an[n-1] = 0;
  for(int i=n-2; i>=0; i--) {
    double sm=0, mx=0;
    int lg = v[i].size();
    for(int x:v[i]) {
      sm += an[x] + 1; mx = max(mx, an[x] + 1);
    }
    
    if (id == i && lg >= 2) {
      double ax = (double)sm / (double)lg;
      double bx = (double)((double)sm - (double)mx) / (double)((double)lg - (double)1);
      an[i] = min(ax, bx);
    } else an[i] = (double)sm / (double)lg;
    //an[i] = (double)sm / (double)lg;
    //cout << i << " " << sm << " " << mx << " " << lg << " " << an[i] <<  endl;
  }
    anan = min(anan, an[0]);
  }
  //for(int i=0; i<n; i++) {
  //  cout << an[i] << endl;
  //}
  cout << fixed << setprecision(7);
  cout << anan << endl;
}