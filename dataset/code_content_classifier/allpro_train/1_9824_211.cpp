#include <bits/stdc++.h>
using namespace std;
int ciel, jiro;
int atack[103], defen[103], value[103];
int a, d;
char line[20];
int num;
long long total;
vector<int> at;
vector<int> quedan;
bool ataca() {
  sort(at.begin(), at.end());
  int size = at.size();
  int pos = 0;
  int i = 0;
  for (; i < size && pos < d; i++) {
    if (at[i] > defen[pos])
      pos++;
    else {
      quedan.push_back(at[i]);
    }
  }
  if (pos == d) {
    for (; i < size; i++) quedan.push_back(at[i]);
  }
  return pos == d;
}
long long firstdef() {
  long long res = 0;
  at.clear();
  quedan.clear();
  for (int i = 0; i < ciel; i++) {
    at.push_back(value[i]);
  }
  if (ataca()) {
    sort(quedan.begin(), quedan.end());
    int size = quedan.size();
    int pos = 0;
    at.clear();
    int i = 0;
    for (; i < size && pos < a; i++) {
      if (quedan[i] >= atack[pos])
        res += quedan[i] - atack[pos++];
      else
        at.push_back(quedan[i]);
    }
    if (pos == a) {
      for (int j = 0; j < at.size(); j++) res += at[j];
      for (; i < size; i++) res += quedan[i];
    }
  }
  return res;
}
int main() {
  cin >> jiro >> ciel;
  for (int i = 0; i < jiro; i++) {
    cin >> line >> num;
    if (line[0] == 'A' && line[1] == 'T' && line[2] == 'K')
      atack[a++] = num;
    else
      defen[d++] = num;
  }
  for (int i = 0; i < ciel; i++) cin >> value[i];
  sort(value, value + ciel);
  sort(atack, atack + a);
  sort(defen, defen + d);
  long long res = 0;
  int pos = 0;
  int i = ciel - 1;
  for (; i >= 0 && pos < a; i--) {
    if (value[i] >= atack[pos])
      res += (value[i] - atack[pos++]);
    else
      break;
  }
  long long q = firstdef();
  cout << max(res, q) << endl;
  return 0;
}
