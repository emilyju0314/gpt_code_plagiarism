#include <bits/stdc++.h>
using namespace std;
int main(){
  while (1){
    int N, Q;
    cin >> N >> Q;
    if (N == 0 && Q == 0){
      break;
    }
    vector<string> S(N);
    vector<int> E(N);
    vector<int> W(N);
    for (int i = 0; i < N; i++){
      cin >> S[i] >> E[i] >> W[i];
    }
    for (int i = 0; i < Q; i++){
      int q;
      cin >> q;
      string ans1 = "Unknown";
      int ans2 = -1;
      for (int j = 0; j < N; j++){
        if (W[j] - E[j] + 1 <= q && q <= W[j]){
          ans1 = S[j];
          ans2 = E[j] - (W[j] - q);
        }
      }
      if (ans1 == "Unknown"){
        cout << ans1 << endl;
      } else {
        cout << ans1 << ' ' << ans2 << endl;
      }
    }
  }
}
