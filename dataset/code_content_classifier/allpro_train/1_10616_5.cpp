#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<long long, long long>> physics;
  vector<pair<long long, long long>> informatics;
  long long signifacance, width;
  auto maximum_possible = 0ll;
  vector<long long> physics_sum;
  vector<long long> informatics_sum;
  vector<long long> physics_significance_sum;
  vector<long long> informatics_significance_sum;
  int n, m, d;
  cin >> n >> m >> d;
  for (auto i = 0; i < n; ++i) {
    cin >> signifacance >> width;
    physics.push_back(make_pair(signifacance, width));
  }
  for (auto i = 0; i < m; ++i) {
    cin >> signifacance >> width;
    informatics.push_back(make_pair(signifacance, width));
  }
  sort(physics.begin(), physics.end(),
       [](pair<long long, long long>& left,
          pair<long long, long long>& right) -> bool {
         if (left.first == right.first) return (left.second < right.second);
         return (left.first > right.first);
       });
  physics_sum.assign(physics.size(), 0);
  physics_significance_sum.assign(physics.size(), 0);
  physics_sum[0] = physics[0].second;
  physics_significance_sum[0] = physics[0].first;
  for (auto i = 1; i < physics.size(); ++i) {
    physics_sum[i] = physics[i].second + physics_sum[i - 1];
    physics_significance_sum[i] =
        physics[i].first + physics_significance_sum[i - 1];
  }
  sort(informatics.begin(), informatics.end(),
       [](pair<long long, long long>& left,
          pair<long long, long long>& right) -> bool {
         if (left.first == right.first) return (left.second < right.second);
         return (left.first > right.first);
       });
  informatics_sum.assign(informatics.size(), 0);
  informatics_significance_sum.assign(informatics.size(), 0);
  informatics_sum[0] = informatics[0].second;
  informatics_significance_sum[0] = informatics[0].first;
  for (auto i = 1; i < informatics.size(); ++i) {
    informatics_sum[i] = informatics[i].second + informatics_sum[i - 1];
    informatics_significance_sum[i] =
        informatics[i].first + informatics_significance_sum[i - 1];
  }
  for (auto it = physics_sum.begin(), it2 = physics_significance_sum.begin();
       it != physics_sum.end(); ++it, it2++) {
    auto it3 =
        upper_bound(informatics_sum.begin(), informatics_sum.end(), (d - *it));
    if (it3 == informatics_sum.begin()) continue;
    if (it3 != informatics_sum.end()) {
      auto index = distance(informatics_sum.begin(), it3);
      if ((*it2 + informatics_significance_sum[index - 1]) > maximum_possible)
        maximum_possible = *it2 + informatics_significance_sum[index - 1];
    } else {
      if ((informatics_significance_sum.back() + *it2) > maximum_possible)
        maximum_possible = informatics_significance_sum.back() + *it2;
    }
  }
  cout << maximum_possible << endl;
  return 0;
}
