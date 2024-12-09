#include <bits/stdc++.h>
using namespace std;
const int MOD1 = 333677;
const int MOD2 = 3626149;
const int MOD3 = 77977;
const int BASE = 29;
int pm1[3000], pm2[3000], pm3[3000];
int hash1[3000], hash2[3000], hash3[3000];
void initPM(int pm[], int mod) {
  pm[0] = 1;
  for (int i = 1; i < 3000; i++) {
    pm[i] = (pm[i - 1] * BASE) % mod;
  }
}
void initHash(const char* str, int len, int hash[], int mod) {
  hash[0] = str[0] - 'a' + 2;
  for (int i = 1; i < len; i++) {
    hash[i] = (hash[i - 1] * BASE + str[i] - 'a' + 2) % mod;
  }
}
int calcHash(int hash[], int pm[], int mod, int i, int j) {
  if (i == 0) return hash[j];
  long long cd = hash[i - 1];
  cd = (cd * pm[j - i + 1]) % mod;
  cd = hash[j] - cd;
  while (cd < 0) {
    cd += mod;
  }
  cd = cd % mod;
  return cd;
}
void calcZ(const char* str, int len, int z[]) {
  z[0] = 1;
  int l = 0, r = 0;
  for (int i = 1; i < len; i++) {
    z[i] = 0;
    if (i <= r) {
      z[i] = min(z[i - l], r - i + 1);
    }
    while (i + z[i] < len && str[z[i]] == str[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
}
int z1[5000];
int z2[5000];
int main() {
  initPM(pm1, MOD1);
  initPM(pm2, MOD2);
  initPM(pm3, MOD3);
  string str;
  string sb;
  string se;
  cin >> str;
  cin >> sb;
  cin >> se;
  initHash(str.c_str(), str.size(), hash1, MOD1);
  initHash(str.c_str(), str.size(), hash2, MOD2);
  initHash(str.c_str(), str.size(), hash3, MOD3);
  string sbstr = sb + str;
  calcZ(sbstr.c_str(), sbstr.size(), z1);
  string strse = str + se;
  reverse(strse.begin(), strse.end());
  calcZ(strse.c_str(), strse.size(), z2);
  int minL = max(sb.size(), se.size());
  int ll = str.size();
  int ans = 0;
  vector<unsigned long long> S;
  for (int i = 0; i <= ll - minL; i++) {
    for (int j = i + minL - 1; j < ll; j++) {
      if (z1[sb.size() + i] >= sb.size() &&
          z2[str.size() - 1 - j + se.size()] >= se.size()) {
        long long h1 = calcHash(hash1, pm1, MOD1, i, j);
        long long h2 = calcHash(hash2, pm2, MOD2, i, j);
        long long h3 = calcHash(hash3, pm3, MOD3, i, j);
        long long t = h1 * 1007010112 + h2 * 1234567 + h3;
        S.push_back(t);
      }
    }
  }
  sort(S.begin(), S.end());
  cout << unique(S.begin(), S.end()) - S.begin() << endl;
  return 0;
}
