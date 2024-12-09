#include <bits/stdc++.h>
using namespace std;
long long w, h, n, nd;
char str[3];
int main() {
  scanf("%lld%lld%lld", &w, &h, &n);
  set<long long> mp1, mp2;
  multiset<long long> mp3, mp4;
  mp1.insert(0), mp1.insert(h);
  mp2.insert(0), mp2.insert(w);
  mp3.insert(h), mp4.insert(w);
  for (int i = 0; i < n; ++i) {
    scanf("%s", str);
    scanf("%lld", &nd);
    if (str[0] == 'H') {
      set<long long>::iterator it1 = mp1.lower_bound(nd);
      long long a = (*it1);
      it1--;
      long long b = (*it1);
      mp1.insert(nd);
      mp3.erase(mp3.find(a - b));
      mp3.insert(a - nd);
      mp3.insert(nd - b);
    } else {
      set<long long>::iterator it2 = mp2.lower_bound(nd);
      long long a = (*it2);
      it2--;
      long long b = (*it2);
      mp2.insert(nd);
      mp4.erase(mp4.find(a - b));
      mp4.insert(a - nd);
      mp4.insert(nd - b);
    }
    multiset<long long>::iterator it11 = mp3.end();
    it11--;
    multiset<long long>::iterator it21 = mp4.end();
    it21--;
    printf("%lld\n", (*it21) * (*it11));
  }
}
