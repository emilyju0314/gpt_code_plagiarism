#include <bits/stdc++.h>
using namespace std;
auto random_address = [] {
  char *p = new char;
  delete p;
  return (uint64_t)p;
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count() *
            (random_address() | 1));
double real_rng(double a = 0, double b = 1) {
  assert(a <= b);
  return uniform_real_distribution<double>(a, b)(rng);
}
long long unif_rng(long long a, long long b) {
  assert(a <= b);
  return uniform_int_distribution<long long>(a, b)(rng);
}
const double TIME_LIMIT = 0.05;
int N, M;
vector<string> league;
vector<int> wins;
int main() {
  long double begin = clock();
  cin >> N >> M;
  league.assign(N, string(N, '?'));
  wins.assign(N, 0);
  for (int i = 0; i < N; i++) league[i][i] = '0';
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    league[u][v] = '1';
    league[v][u] = '0';
    wins[u]++;
  }
  vector<pair<int, int>> changeable;
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++)
      if (league[i][j] == '?') {
        changeable.emplace_back(i, j);
        league[i][j] = '1';
        league[j][i] = '0';
        wins[i]++;
      }
  vector<string> output = league;
  int current = 0;
  for (int i = 0; i < N; i++) current += wins[i] * (wins[i] - 1) / 2;
  int best = current;
  long long total = 0;
  const double INIT_TEMPERATURE = 10;
  const double FINAL_TEMPERATURE = 0.01;
  const int CHANGE_CUTOFF = 100;
  if (changeable.empty()) goto finish;
  while ((clock() - begin) / CLOCKS_PER_SEC < TIME_LIMIT) {
    double time_fraction = (clock() - begin) / CLOCKS_PER_SEC / TIME_LIMIT;
    double temperature =
        INIT_TEMPERATURE *
        pow(FINAL_TEMPERATURE / INIT_TEMPERATURE, time_fraction);
    vector<double> probabilities(CHANGE_CUTOFF);
    for (int change = 0; change < CHANGE_CUTOFF; change++)
      probabilities[change] = exp(-change / temperature);
    for (int iter = 0; iter < 10000; iter++) {
      int index = rng() % changeable.size();
      int a = changeable[index].first, b = changeable[index].second;
      total++;
      if (league[a][b] != '1') swap(a, b);
      int change = wins[b] - wins[a] + 1;
      if (change <= 0 ||
          (change < CHANGE_CUTOFF && real_rng() < probabilities[change])) {
        current += change;
        league[a][b] = '0';
        league[b][a] = '1';
        wins[a]--;
        wins[b]++;
        if (current < best) {
          best = current;
          output = league;
        }
      }
    }
  }
finish:
  for (int i = 0; i < N; i++) cout << output[i] << '\n';
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int count = 0;
    for (int j = 0; j < N; j++) count += output[i][j] - '0';
    sum += count * (count - 1) / 2;
  }
  assert(sum == best);
}
