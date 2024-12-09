#include <bits/stdc++.h>
using namespace std;
int _, n, t, a, b, T;
vector<int> cost;
vector<pair<int, int> > mand;
void run_case() {
  long long best = 0, hard = 0, easy = 0;
  cin >> n >> t >> a >> b;
  cost.resize(n);
  mand.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> _;
    if (_)
      hard++, cost[i] = b;
    else
      easy++, cost[i] = a;
  }
  for (int i = 0; i < n; i++) {
    cin >> mand[i].first;
    mand[i].second = i;
  }
  if (accumulate(cost.begin(), cost.end(), 0LL) <= t) {
    cout << n << endl;
    return;
  }
  sort(mand.begin(), mand.end());
  long long mand_score = 0, tot_time = 0, mand_time = 0;
  while (mand_score < n) {
    tot_time = mand[mand_score].first - 1;
    if (tot_time >= mand_time) {
      long long spare_time = tot_time - mand_time;
      long long easy_score = min(easy, spare_time / a);
      long long hard_score = min(hard, (spare_time - easy_score * a) / b);
      best = max(best, easy_score + hard_score + mand_score);
    }
    int cur_mand = mand[mand_score].first;
    while (mand_score < n && mand[mand_score].first == cur_mand) {
      if (cost[mand[mand_score].second] == a)
        easy--, mand_time += a;
      else
        hard--, mand_time += b;
      mand_score++;
    }
  }
  cout << best << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    run_case();
  }
  return 0;
}
