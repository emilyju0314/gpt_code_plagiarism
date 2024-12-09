#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int ret[MAXN];
pair<int, int> F[MAXN];
set<int> count;
int N, M, foo;
bool amb, imp;
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    scanf("%d", &foo);
    F[foo].first++;
    F[foo].second = i;
  }
  for (int i = 0; i < M; i++) {
    scanf("%d", &foo);
    if (F[foo].first > 1)
      amb = true;
    else if (F[foo].first == 0)
      imp = true;
    else
      ret[i] = F[foo].second + 1;
  }
  if (imp)
    cout << "Impossible" << endl;
  else if (amb)
    cout << "Ambiguity" << endl;
  else {
    cout << "Possible" << endl;
    for (int i = 0; i < M; i++) printf("%d ", ret[i]);
  }
  return 0;
}
