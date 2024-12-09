#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> board(6000, 0);
    board[0] = (1 << 5) - 1; // sentinel
    while (n--) {
      int d, p, q;
      cin >> d >> p >> q;

      --q;
      for (int i = 6000-1; i > 0; --i) {
	if (d == 1) {
	  // hor
	  int block = 0;
	  for (int j = 0; j < p; ++j)
	    block |= (1 << (q+j));
	  
	  if (board[i-1] & block) {
	    board[i] |= block;
	    break;
	  }
	} else {
	  // ver
	  if (board[i-1] & (1 << q)) {
	    for (int j = 0; j < p; ++j)
	      board[i+j] |= (1 << q);
	    break;
	  }
	}
      }

      int vanish = 0;
      for (int i = 1; i < 6000; ++i) {
	if (board[i] == (1 << 5) -1) {
	  ++vanish;
	} else if (vanish > 0) {
	    board[i-vanish] = board[i];
	    board[i] = 0;
	}
      }
    }

    int ans = 0;
    for (unsigned int i = 1; i < board.size(); ++i)
      ans += __builtin_popcount(board[i]);
    cout << ans << endl;
  }
  return 0;
}