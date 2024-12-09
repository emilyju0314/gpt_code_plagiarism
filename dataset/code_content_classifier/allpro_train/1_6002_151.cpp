#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[5][5];
  int xMid = 2;
  int yMid = 2;
  int xCord = 0;
  int yCord = 0;
  for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 5; y++) {
      int num;
      cin >> num;
      arr[x][y] = num;
      if (arr[x][y] == 1) {
        xCord = x;
        yCord = y;
      }
    }
  }
  int numMoves = std::abs((xCord - xMid)) + std::abs((yCord - yMid));
  cout << numMoves << endl;
}
