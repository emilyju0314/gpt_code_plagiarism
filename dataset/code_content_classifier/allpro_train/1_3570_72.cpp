#include <bits/stdc++.h>
using namespace std;
vector<int> text;
int n, k;
long long p = 31;
bool vowel(char ch) {
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
int type_of(string &s1, string &s2, string &s3, string &s4) {
  long long hash1 = 0, hash2 = 0, hash3 = 0, hash4 = 0;
  long long cur_p = 1;
  int dt = k;
  for (int i = int(s1.size()) - 1; i >= 0 && dt > 0; i--) {
    if (vowel(s1[i])) dt--;
    hash1 += (s1[i] - 'a' + 1) * cur_p;
    cur_p *= p;
  }
  if (dt > 0) return 0;
  cur_p = 1;
  dt = k;
  for (int i = int(s2.size()) - 1; i >= 0 && dt > 0; i--) {
    if (vowel(s2[i])) dt--;
    hash2 += (s2[i] - 'a' + 1) * cur_p;
    cur_p *= p;
  }
  if (dt > 0) return 0;
  cur_p = 1;
  dt = k;
  for (int i = int(s3.size()) - 1; i >= 0 && dt > 0; i--) {
    if (vowel(s3[i])) dt--;
    hash3 += (s3[i] - 'a' + 1) * cur_p;
    cur_p *= p;
  }
  if (dt > 0) return 0;
  cur_p = 1;
  dt = k;
  for (int i = int(s4.size()) - 1; i >= 0 && dt > 0; i--) {
    if (vowel(s4[i])) dt--;
    hash4 += (s4[i] - 'a' + 1) * cur_p;
    cur_p *= p;
  }
  if (dt > 0) return 0;
  if (hash1 == hash2 && hash2 == hash3 && hash3 == hash4 && hash4 == hash1)
    return 4;
  if (hash1 == hash2 && hash3 == hash4) return 3;
  if (hash1 == hash3 && hash2 == hash4) return 2;
  if (hash1 == hash4 && hash2 == hash3) return 1;
  return 0;
}
int main() {
  cin >> n >> k;
  string s1, s2, s3, s4;
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2 >> s3 >> s4;
    text.push_back(type_of(s1, s2, s3, s4));
    if (text.back() == 0) {
      cout << "NO\n";
      return 0;
    }
  }
  int frst = -1;
  for (int i = 0; i < text.size(); i++) {
    if (text[i] == 4) continue;
    if (frst == -1) {
      frst = text[i];
      continue;
    }
    if (text[i] != frst) {
      cout << "NO\n";
      return 0;
    }
  }
  if (frst == -1) cout << "aaaa\n";
  if (frst == 3) cout << "aabb\n";
  if (frst == 2) cout << "abab\n";
  if (frst == 1) cout << "abba\n";
  return 0;
}
