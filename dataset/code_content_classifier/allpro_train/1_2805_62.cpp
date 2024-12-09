#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int count = n, room_count = 0;
  set<int> room, maybe;
  vector<bool> leader(n + 1, true), first_char(n + 1, false);
  vector<pair<char, int> > commands(m);
  for (int i = 0; i < m; ++i) {
    scanf(" %c %d", &commands[i].first, &commands[i].second);
    if (!first_char[commands[i].second]) {
      first_char[commands[i].second] = true;
      if (commands[i].first == '-') {
        room_count++;
        room.insert(commands[i].second);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    if (commands[i].first == '+') {
      if (room_count != 0 && leader[commands[i].second]) {
        leader[commands[i].second] = false;
        count--;
      }
      if (room_count == 0) {
        maybe.insert(commands[i].second);
      }
      room.insert(commands[i].second);
      room_count++;
    } else {
      if (room_count > 1 && leader[commands[i].second]) {
        leader[commands[i].second] = false;
        count--;
      }
      if (room_count == 1) {
        maybe.insert(commands[i].second);
      }
      room.erase(commands[i].second);
      room_count--;
    }
  }
  if ((int(maybe.size())) > 1) {
    for (typeof((maybe).begin()) i = (maybe).begin(); i != (maybe).end(); i++) {
      if (leader[*i]) {
        leader[*i] = false;
        count--;
      }
    }
  }
  printf("%d\n", count);
  for (int i = 0; i < n; ++i) {
    if (leader[i + 1]) printf("%d ", i + 1);
  }
  return 0;
}
