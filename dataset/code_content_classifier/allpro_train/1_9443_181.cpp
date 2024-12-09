#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  deque<int> Vec;
  for (int i = 0; i < N; i++) {
    int cmd1, cmd2, ele;
    cin >> cmd1;
    if (cmd1 == 0) {
      cin >> cmd2 >> ele;
      if (cmd2 == 0)
        Vec.push_front(ele);
      else if (cmd2 == 1)
        Vec.push_back(ele);
    } else if (cmd1 == 1) {
      cin >> ele;
      cout << Vec.at(ele) << endl;
    } else if (cmd1 == 2) {
      cin >> cmd2;
      if(cmd2 == 0)Vec.pop_front();
      else if(cmd2 == 1)Vec.pop_back();
    }
  }
}
