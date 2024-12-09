#include <bits/stdc++.h>
using namespace std;
class state {
 public:
  string line;
  int ind;
};
vector<string> lesha;
vector<vector<string> > torProbs;
map<string, int> m;
int countInv(vector<string>& lesha) {
  int k = 0;
  for (int i = 1; i < lesha.size(); i++) {
    int curInd = m[lesha[i]];
    for (int j = i - 1; j >= 0; j--) {
      int privInd = m[lesha[j]];
      if (privInd > curInd) k++;
    }
  }
  int ret = lesha.size() * (lesha.size() - 1);
  ret /= 2;
  ret -= k;
  ret++;
  return ret;
}
bool ok(int ind, vector<string>& lesha) {
  int ii = 0;
  for (int i = 0; i < torProbs[ind].size(); i++) {
    if (torProbs[ind][i] == lesha[ii]) ii++;
    if (ii == lesha.size()) return true;
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  string word = "";
  for (int i = 0; i < n; i++) {
    cin >> word;
    lesha.push_back(word);
    m[word] = i;
  }
  int mm = 0;
  cin >> mm;
  int k;
  string s = "";
  for (int i = 0; i < mm; i++) {
    cin >> k;
    vector<string> tmp;
    for (int j = 0; j < k; j++) {
      cin >> s;
      tmp.push_back(s);
    }
    torProbs.push_back(tmp);
  }
  sort(lesha.begin(), lesha.end());
  vector<int> res(torProbs.size(), 0);
  do {
    int inv = countInv(lesha);
    for (int i = 0; i < mm; i++) {
      if (ok(i, lesha)) {
        res[i] = max(res[i], inv);
      }
    }
  } while (next_permutation(lesha.begin(), lesha.end()));
  int mns = 0;
  int ind = -1;
  for (int i = 0; i < res.size(); i++) {
    if (res[i] == 0) continue;
    if (mns < res[i]) {
      mns = res[i];
      ind = i;
    }
  }
  if (ind == -1) {
    cout << "Brand new problem!"
         << "\n";
  } else {
    cout << ind + 1 << endl;
    string tmp = "";
    tmp += "[";
    tmp += ":";
    for (int i = 0; i < mns; i++) {
      tmp += "|";
    }
    tmp += ":";
    tmp += "]";
    cout << tmp << endl;
  }
  return 0;
}
