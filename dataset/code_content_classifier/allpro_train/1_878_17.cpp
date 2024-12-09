#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 100000;
vector<ll> lengths(MAX_N);
vector<ll> cum_len(MAX_N);
void init() {
  lengths[0] = 0;
  for (int i = (1); i < (MAX_N); i++) {
    ll cnt = 0;
    ll now = i;
    while (now) ++cnt, now /= 10;
    lengths[i] = lengths[i - 1] + cnt;
  }
  cum_len[0] = 0;
  for (int i = (1); i < (MAX_N); i++) cum_len[i] = cum_len[i - 1] + lengths[i];
}
int search(int k) {
  vector<ll>::iterator cum_itr = lower_bound(cum_len.begin(), cum_len.end(), k);
  ll cum_sum = *cum_itr;
  int posi = cum_itr - cum_len.begin();
  if (cum_sum == k) return posi % 10;
  ll length = lengths[posi] - (cum_sum - k);
  vector<ll>::iterator len_itr =
      lower_bound(lengths.begin(), lengths.end(), length);
  int len_posi = len_itr - lengths.begin();
  int len_v = *len_itr;
  if (len_v == length)
    return len_posi % 10;
  else {
    int d = len_v - length;
    for (int i = (0); i < (d); i++) len_posi /= 10;
    return len_posi % 10;
  }
}
int main() {
  init();
  int q;
  cin >> q;
  for (int i = (0); i < (q); i++) {
    int k;
    cin >> k;
    printf("%d\n", search(k));
  }
  return 0;
}
