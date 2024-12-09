#include <bits/stdc++.h>
using namespace std;
void bits_add_bit(bitset<(200000 + 31)> &bits, unsigned int pow) {
  while (pow < (200000 + 31)) {
    if (bits[pow] == 0) {
      bits[pow] = 1;
      break;
    } else {
      bits[pow] = 0;
      pow++;
    }
  }
}
void bits_add_uint(bitset<(200000 + 31)> &bits, unsigned int n,
                   unsigned int pow) {
  for (unsigned int bit = 0; bit < 31; bit++) {
    if (n & (1 << bit)) {
      bits_add_bit(bits, pow + bit);
    }
  }
}
bool bits_diff(bitset<(200000 + 31)> &bits, bitset<(200000 + 31)> &bits1,
               bitset<(200000 + 31)> &bits2) {
  bool greater = false;
  for (unsigned int bit = (200000 + 31) - 1; bit >= 0; bit--) {
    if (bits1[bit] > bits2[bit]) {
      greater = true;
      break;
    }
    if (bits1[bit] < bits2[bit]) {
      break;
    }
  }
  if (!greater) {
    swap(bits1, bits2);
  }
  bool debt = false;
  for (unsigned int bit = 0; bit < (200000 + 31); bit++) {
    if (!debt) {
      bits[bit] = bits1[bit] != bits2[bit];
      debt = bits1[bit] < bits2[bit];
    } else {
      bits[bit] = bits1[bit] == bits2[bit];
      debt = bits1[bit] <= bits2[bit];
    }
  }
  return greater;
}
int count_ways(bitset<(200000 + 31)> &bits, vector<int> &A, unsigned int K) {
  unsigned int leftmost, rightmost;
  for (unsigned int i = 0; i < (200000 + 31); i++) {
    if (bits[i]) {
      rightmost = i;
      break;
    }
  }
  for (unsigned int i = (200000 + 31) - 1; i >= 0; i--) {
    if (bits[i]) {
      leftmost = i;
      break;
    }
  }
  unsigned int width = leftmost - rightmost + 1;
  if (width > 31) {
    return 0;
  }
  unsigned int terminator = 0;
  for (unsigned int i = rightmost; i <= leftmost; i++) {
    terminator += bits[i] << (i - rightmost);
  }
  int result = 0;
  for (unsigned int i = 0; i <= rightmost; i++) {
    if (width + i > 31) {
      break;
    }
    unsigned int index = rightmost - i;
    if (index < A.size()) {
      int diff = A[index] - (terminator << i);
      if ((abs(diff) <= K) && !(diff == 0 && index == A.size() - 1)) {
        result++;
      }
    }
  }
  return result;
}
int main() {
  unsigned int N, K;
  scanf("%d%d", &N, &K);
  vector<int> A(N + 1);
  bitset<(200000 + 31)> PosBits, NegBits, Bits;
  for (unsigned int i = 0; i <= N; i++) {
    scanf("%d", &A[i]);
    if (A[i] > 0) {
      bits_add_uint(PosBits, A[i], i);
    } else {
      bits_add_uint(NegBits, -A[i], i);
    }
  }
  bool positive = bits_diff(Bits, PosBits, NegBits);
  if (!positive) {
    for (unsigned int i = 0; i <= N; i++) {
      A[i] = -A[i];
    }
  }
  printf("%d\n", count_ways(Bits, A, K));
  return 0;
}
