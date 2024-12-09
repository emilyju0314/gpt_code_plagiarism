#include <bits/stdc++.h>
using namespace std;
struct Node {
  int n, s, e, w;
  Node() : n(0), s(0), e(0), w(0) {}
};
void constructMap(vector<vector<Node> > &mp, vector<string> &v, int N, int M) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (v[i][j] == '#')
        mp[i][j].w = -1;
      else
        mp[i][j].w = mp[i][j - 1].w + 1;
  for (int i = 0; i < N; i++)
    for (int j = M - 1; j >= 0; j--)
      if (v[i][j] == '#')
        mp[i][j].e = -1;
      else
        mp[i][j].e = mp[i][j + 1].e + 1;
  for (int j = 0; j < M; j++)
    for (int i = N - 1; i >= 0; i--)
      if (v[i][j] == '#')
        mp[i][j].s = -1;
      else
        mp[i][j].s = mp[i + 1][j].s + 1;
  for (int j = 0; j < M; j++)
    for (int i = 0; i < N; i++)
      if (v[i][j] == '#')
        mp[i][j].n = -1;
      else
        mp[i][j].n = mp[i - 1][j].n + 1;
}
bool execute(vector<pair<char, int> > &ins, int i, int j,
             vector<vector<Node> > &mp) {
  for (int k = 0; k < ins.size(); k++) {
    switch (ins[k].first) {
      case 'N':
        if (mp[i][j].n < ins[k].second) return false;
        i = i - ins[k].second;
        break;
      case 'S':
        if (mp[i][j].s < ins[k].second) return false;
        i = i + ins[k].second;
        break;
      case 'E':
        if (mp[i][j].e < ins[k].second) return false;
        j = j + ins[k].second;
        break;
      case 'W':
        if (mp[i][j].w < ins[k].second) return false;
        j = j - ins[k].second;
        break;
    }
  }
  return true;
}
string possiblePaths(vector<string> &v, vector<pair<char, int> > &ins, int N,
                     int M) {
  vector<vector<Node> > mp(N, vector<Node>(M));
  constructMap(mp, v, N, M);
  vector<bool> alphabets(26);
  string s = "";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      if ('A' <= v[i][j] && v[i][j] <= 'Z' && execute(ins, i, j, mp)) {
        s.push_back(v[i][j]);
      }
  }
  sort(s.begin(), s.end());
  if (s.empty()) s = "no solution";
  return s;
}
int main() {
  int N, M;
  vector<string> v;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string t;
    cin >> t;
    v.push_back(t);
  }
  int K;
  cin >> K;
  vector<pair<char, int> > instruction;
  for (int i = 0; i < K; i++) {
    pair<char, int> e;
    cin >> e.first >> e.second;
    instruction.push_back(e);
  }
  cout << possiblePaths(v, instruction, N, M) << endl;
  return 0;
}
