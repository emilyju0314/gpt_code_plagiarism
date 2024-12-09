#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> stones(3);
  for (int i = 0; i < 3; i++) {
    cin >> stones[i];
  }
  
  vector<string> colors(n);
  for (int i = 0; i < n; i++) {
    cin >> colors[i];
  }
  
  vector<pair<int, int>> moves;
  
  // Check if initial stones are on vertices 1, 2 and 3
  if ((stones[0] == 1 && stones[1] == 2 && stones[2] == 3) ||
      (stones[0] == 2 && stones[1] == 1 && stones[2] == 3) ||
      (stones[0] == 3 && stones[1] == 1 && stones[2] == 2) ||
      (stones[0] == 2 && stones[1] == 3 && stones[2] == 1) ||
      (stones[0] == 1 && stones[1] == 3 && stones[2] == 2) ||
      (stones[0] == 3 && stones[1] == 2 && stones[2] == 1)) {
    cout << "0\n";
  } else {
    int moves_required = 0;
    
    // Try to move stones to vertices 1, 2 and 3
    while (stones[0] != 1 || stones[1] != 2 || stones[2] != 3) {
      bool moved = false;
      
      for (int i = 0; i < n; i++) {
        if (colors[stones[0] - 1][i] == colors[stones[1] - 1][stones[2] - 1]) {
          moves.push_back({stones[0], i + 1});
          stones[0] = i + 1;
          moved = true;
          break;
        }
      }
      
      if (!moved) {
        break;
      }
      
      moves_required++;
    }
    
    if (stones[0] == 1 && stones[1] == 2 && stones[2] == 3) {
      cout << moves_required << endl;
      for (int i = 0; i < moves.size(); i++) {
        cout << moves[i].first << " " << moves[i].second << endl;
      }
    } else {
      cout << "-1\n";
    }
  }
  
  return 0;
}