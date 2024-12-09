#include <bits/stdc++.h>
using namespace std;
const long long mod7 = 1000000007;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it->substr((*it)[0] == ' ', it->length()) << ": " << a << " ";
  err(++it, args...);
}
template <typename T>
long long biggest(T x) {
  long long b_i = 0;
  for (long long i = 0; i < x.size(); i++) {
    if (x[b_i] < x[i]) {
      b_i = i;
    }
  }
  return b_i;
}
template <typename T>
long long smallest(T x) {
  long long s_i = 0;
  for (long long i = 0; i < x.size(); i++) {
    if (x[s_i] > x[i]) {
      s_i = i;
    }
  }
  return s_i;
}
template <typename T>
string tostring(T num) {
  stringstream convert;
  convert << num;
  return convert.str();
}
template <typename T>
long long tonumber(T stringNum) {
  long long a;
  stringstream convert;
  convert << stringNum;
  convert >> a;
  return a;
}
long long A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W,
    X, Y, Z;
char C1, C2, C3, C4;
string S1, S2, S3, S4;
vector<long long> V1, V2, V3, V4;
bool B1, B2;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.clear();
  cin >> N >> X;
  for (long long i = 0; i < N; i++) {
    cin >> A;
    S += A;
  }
  cout << round(ceil(abs(S / (double)X))) << endl;
}
