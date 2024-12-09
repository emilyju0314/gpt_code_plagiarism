#include <bits/stdc++.h>
using namespace std;
class State {
 public:
  int count[4];
  State() { count[0] = count[1] = count[2] = count[3] = 0; }
  State(const State& s) {
    for (int k = 0; k < 4; ++k) count[k] = s.count[k];
  }
  long long getHash() {
    long long hash = 0;
    for (int k = 0; k < 4; ++k) {
      hash ^= count[k];
      hash <<= 15;
    }
    return hash;
  }
};
void printState(State s) {
  printf("s counts: %i %i %i %i\n", s.count[0], s.count[1], s.count[2],
         s.count[3]);
}
int main() {
  vector<State> array;
  array.push_back(State());
  int n;
  cin >> n;
  char c;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    if (c == '?') {
      unordered_map<long long, int> mmap;
      vector<State> newA;
      for (int j = 0, size = array.size(); j < size; ++j) {
        int minCount = 100000;
        for (int k = 0; k < 4; ++k) {
          minCount = min(minCount, array[j].count[k]);
        }
        State origS = State(array[j]);
        for (int k = 0; k < 4; ++k) {
          if (minCount == origS.count[k]) {
            State s = State(origS);
            s.count[k]++;
            if (mmap.find(s.getHash()) != mmap.end()) continue;
            mmap[s.getHash()] = 1;
            newA.push_back(s);
          }
        }
      }
      array.clear();
      array.insert(array.begin(), newA.begin(), newA.end());
    } else {
      int k = 0;
      if (c == 'G') k = 0;
      if (c == 'H') k = 1;
      if (c == 'R') k = 2;
      if (c == 'S') k = 3;
      for (int j = 0, size = array.size(); j < size; ++j) array[j].count[k]++;
    }
  }
  bool possibles[4];
  possibles[0] = possibles[1] = possibles[2] = possibles[3] = false;
  for (int j = 0, size = array.size(); j < size; ++j) {
    int minCount = 100000;
    for (int k = 0; k < 4; ++k) {
      minCount = min(minCount, array[j].count[k]);
    }
    State origS = array[j];
    for (int k = 0; k < 4; ++k) {
      if (minCount == origS.count[k]) {
        possibles[k] = true;
      }
    }
  }
  if (possibles[0]) cout << "Gryffindor" << endl;
  if (possibles[1]) cout << "Hufflepuff" << endl;
  if (possibles[2]) cout << "Ravenclaw" << endl;
  if (possibles[3]) cout << "Slytherin" << endl;
}
