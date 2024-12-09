#include <bits/stdc++.h>
using namespace std;
bool comp(pair<pair<long long, long long>, int> a,
          pair<pair<long long, long long>, int> b) {
  return ((a.first.first * b.first.second) > (a.first.second * b.first.first));
}
vector<string> gg;
vector<pair<pair<long long, long long>, int>> ar;
int main() {
  std::ios::sync_with_stdio(false);
  ;
  int n;
  std::cin >> n;
  long long tot = 0;
  for (int i = 0; i < n; i++) {
    string str;
    long long sc = 0, hc = 0;
    std::cin >> str;
    for (int j = 0; j < str.length(); j++) {
      if (str[j] == 's')
        sc++;
      else {
        hc++;
      }
    }
    gg.push_back(str);
    ar.push_back(make_pair(make_pair(sc, hc), i));
  }
  sort(ar.begin(), ar.end(), comp);
  string fin = "";
  for (int i = 0; i < n; i++) {
    fin = fin.append(gg[ar[i].second]);
  }
  long long sc = 0, hc = 0;
  for (int i = 0; i < fin.length(); i++) {
    if (fin[i] == 's')
      sc++;
    else {
      hc++;
      tot += sc;
    }
  }
  std::cout << tot << endl;
  return 0;
}
