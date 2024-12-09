#include <bits/stdc++.h>
using namespace std;
struct PARK {
  int car_id, car_length, rear_pos;
} park[100];
int L, b, f, park_sz;
void Remove(int id) {
  bool swap = false;
  for (int i = 0; i < park_sz; i++) {
    if (swap) {
      park[i - 1] = park[i];
      continue;
    }
    if (park[i].car_id == id) swap = true;
  }
  park_sz--;
}
void Place(int id, int length) {
  int back = 0, pos = park_sz, loc = -1;
  for (int i = 0; i < park_sz; i++) {
    if (back + length + f <= park[i].rear_pos) {
      pos = i;
      loc = back;
      break;
    }
    back = park[i].rear_pos + park[i].car_length + b;
  }
  if (loc < 0 && back + length <= L) loc = back;
  if (loc >= 0) {
    for (int i = park_sz; i > pos; i--) park[i] = park[i - 1];
    park[pos].car_id = id;
    park[pos].car_length = length;
    park[pos].rear_pos = loc;
    park_sz++;
  }
  cout << loc << endl;
}
int main() {
  int n;
  cin >> L >> b >> f >> n;
  park_sz = 0;
  for (int i = 0; i < n; i++) {
    int op, arg;
    cin >> op >> arg;
    if (op == 1)
      Place(i + 1, arg);
    else
      Remove(arg);
  }
  return 0;
}
