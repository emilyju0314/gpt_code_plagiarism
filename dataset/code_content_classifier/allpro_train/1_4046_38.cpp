#include <iostream>
using namespace std;

int main(){
  int64_t H, W, ans;
  cin >> H >> W;
  ans = (H * W + 1) / 2;
  if (H == 1 || W == 1) cout << 1;
  else cout << ans;
}