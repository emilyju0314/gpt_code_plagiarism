#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
inline int cnt(int X) {
  int RT = -1;
  while (X) {
    X >>= 1;
    ++RT;
  }
  return RT;
}
void init() {
  int a;
  scanf("%d", &a);
  printf("%d\n", cnt(a) == cnt(a + 1) ? ((1 << (cnt(a) + 1)) - 1)
                                      : (mp[a] ? mp[a] : 1));
}
int main() {
  mp[15] = 5;
  mp[63] = 21;
  mp[255] = 85;
  mp[511] = 73;
  mp[1023] = 341;
  mp[2047] = 89;
  mp[4095] = 1365;
  mp[16383] = 5461;
  mp[32767] = 4681;
  mp[65535] = 21845;
  mp[262143] = 87381;
  mp[1048575] = 349525;
  mp[2097151] = 299593;
  mp[4194303] = 1398101;
  mp[8388607] = 178481;
  mp[16777215] = 5592405;
  mp[33554431] = 1082401;
  int T;
  scanf("%d", &T);
  while (T--) {
    init();
  }
  return 0;
}
