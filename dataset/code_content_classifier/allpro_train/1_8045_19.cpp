#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_H = 64;
const int MAX_W = 64;

/* typedef */

typedef unsigned long long ull;
typedef vector<ull> vull;

struct Block {
  int h, w;
  vull bits;

  void read() {
    cin >> h >> w;
    bits.assign(h, 0ULL);
    
    for (int y = 0; y < h; y++) {
      string line;
      cin >> line;
      for (int x = 0; x < w; x++) {
	if (line[x] == '#') bits[y] |= (1ULL << x);
      }
    }
  }

  void normalize() {
    while (bits.front() == 0) bits.erase(bits.begin()), h--;
    while (bits.back() == 0) bits.erase(bits.end() - 1), h--;

    int min_lsp = w, min_rsp = w;
    for (vull::iterator vit = bits.begin(); vit != bits.end(); vit++) {
      int lsp, rsp;
      for (lsp = 0; (*vit & (1ULL << lsp)) == 0; lsp++);
      for (rsp = 0; (*vit & (1ULL << (w - 1 - rsp))) == 0; rsp++);
      if (min_lsp > lsp) min_lsp = lsp;
      if (min_rsp > rsp) min_rsp = rsp;
    }
    //printf("min_lsp = %d, min_rsp = %d\n", min_lsp, min_rsp);

    if (min_lsp > 0) {
      for (vull::iterator vit = bits.begin(); vit != bits.end(); vit++)
	*vit >>= min_lsp;
      w -= min_lsp;
    }
    w -= min_rsp;
    //printf("h=%d,w=%d\n", h, w);
  }

  void rotate() {
    vull bits0(bits);

    swap(h, w);
    bits.assign(h, 0ULL);

    for (int y = 0, x0 = h - 1; y < h; y++, x0--)
      for (int x = 0, y0 = 0; x < w; x++, y0++)
	if (bits0[y0] & (1ULL << x0)) bits[y] |= (1ULL << x);
  }

  void print() {
    printf("h=%d,w=%d\n", h, w);
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++)
	cout << ((bits[y] & (1ULL << x)) != 0 ? '#' : '.');
      cout << endl;
    }
  }
};

/* global variables */

/* subroutines */

int max_fill_len(Block& blk, Block& brd) {
  int mfl = -1;
  int dh = brd.h - blk.h, dw = brd.w - blk.w;
  if (dh < 0 || dw < 0) return mfl;

  ull allbits = (~0ULL >> (MAX_W - brd.w));
  
  for (int h0 = 0; h0 <= dh; h0++)
    for (int w0 = 0; w0 <= dw; w0++) {
      int fl = 0;
      bool ok = true;

      for (int y = 0; y < blk.h; y++) {
	ull blkbit = (blk.bits[y] << w0), brdbit = brd.bits[y + h0];
	if ((blkbit & brdbit) != 0) {
	  ok = false;
	  break;
	}
	if ((blkbit | brdbit) == allbits) fl++;
      }
  
      if (ok && mfl < fl) mfl = fl;
      //printf("(h0,w0)=(%d,%d): ok=%d, fl=%d\n", h0, w0, ok, fl);
    }

  return mfl;
}

/* main */

int main() {
  int n;
  cin >> n;

  while (n--) {
    Block blk, brd;
    blk.read();
    brd.read();

    blk.normalize();
    //blk.print();

    int max_fl = -1;
    
    for (int di = 0; di < 4; di++) {
      //blk.print();
      int fl = max_fill_len(blk, brd);
      if (max_fl < fl) max_fl = fl;

      blk.rotate();
    }

    cout << max_fl << endl;
  }

  return 0;
}