#include <bits/stdc++.h>
using namespace std;
const bool online_judge = true;
const long long inf = 1LL << 60;
long long toInt(string s) {
  long long res;
  stringstream ss;
  ss << s;
  ss >> res;
  return res;
}
string toString(long long n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
void run() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  for (long long i = k - 1;; i = (i + 1) % n) {
    if (v[i] == 1) {
      cout << (i + 1) << endl;
      return;
    }
  }
}
int main(int argc, char *argv[]) {
  if (online_judge) {
    ifstream ifile("input.txt");
    if (ifile) freopen("input.txt", "rt", stdin);
    if (ifile) freopen("output.txt", "wt", stdout);
  }
  run();
  return 0;
}
