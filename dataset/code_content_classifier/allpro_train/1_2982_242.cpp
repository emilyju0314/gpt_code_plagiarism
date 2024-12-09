#include <bits/stdc++.h>
using namespace std;
int main() {
  string homeName, awayName;
  map<int, int> homeFouls, awayFouls;
  map<int, bool> ocrHomeFouls, ocrAwayFouls;
  int numFouls;
  cin >> homeName >> awayName;
  cin >> numFouls;
  while (numFouls--) {
    int player, minute;
    char team, card;
    cin >> minute >> team >> player >> card;
    if (team == 'a') {
      awayFouls[player] += (card == 'r') ? 2 : 1;
      if (awayFouls[player] >= 2 && !ocrAwayFouls[player]) {
        ocrAwayFouls[player] = true;
        cout << awayName << " " << player << " " << minute << endl;
      }
    } else {
      homeFouls[player] += (card == 'r') ? 2 : 1;
      if (homeFouls[player] >= 2 && !ocrHomeFouls[player]) {
        ocrHomeFouls[player] = true;
        cout << homeName << " " << player << " " << minute << endl;
      }
    }
  }
  return 0;
}
