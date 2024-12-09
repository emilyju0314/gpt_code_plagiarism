#include <bits/stdc++.h>
using namespace std;
const long long int maxN = 9000;
vector<long long int> atack, defend, fox, cop;
long long int mx, n, m, ansq, ans[maxN];
bool mrk[maxN];
void input() {
  cin >> n >> m;
  for (long long int i = 1; i <= n; i++) {
    string s;
    long long int x;
    cin >> s >> x;
    if (s == "ATK")
      atack.push_back(x);
    else
      defend.push_back(x);
  }
  for (long long int i = 1; i <= m; i++) {
    long long int x;
    cin >> x;
    fox.push_back(x);
  }
  sort(atack.begin(), atack.end());
  sort(defend.begin(), defend.end());
  sort(fox.begin(), fox.end());
}
void attack_done() {
  for (long long int i = 0; i <= ((int)(atack).size()) - 1; i++) {
    long long int d = ((int)(fox).size());
    for (long long int j = i; j >= 0; j--) {
      d--;
      if (d >= 0 && fox[d] >= atack[j])
        ans[i] += fox[d] - atack[j];
      else {
        ans[i] = -1;
        break;
      }
    }
    mx = max(mx, ans[i]);
  }
}
bool defend_done() {
  for (long long int j = 0; j <= ((int)(defend).size()) - 1; j++) {
    long long int d = 0;
    while (d < ((int)(fox).size()) && (fox[d] <= defend[j] || mrk[d])) d++;
    if (d == ((int)(fox).size())) return false;
    mrk[d] = true;
  }
  long long int i = ((int)(atack).size()) - 1;
  long long int d = ((int)(fox).size());
  for (long long int j = i; j >= 0; j--) {
    d--;
    while (mrk[d] && d >= 0) d--;
    if (d >= 0 && fox[d] >= atack[j] && !mrk[d]) {
      ansq += fox[d] - atack[j], mrk[d] = true;
    } else
      return false;
  }
  for (long long int i = 0; i <= ((int)(fox).size()) - 1; i++) {
    if (!mrk[i]) ansq += fox[i];
  }
  mx = max(mx, ansq);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  input();
  attack_done();
  defend_done();
  cout << mx << endl;
}
