#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int BUFFER_SIZE = 1 << 15;
char input_buffer[BUFFER_SIZE];
int input_pos = 0, input_len = 0;
void _update_input_buffer() {
  input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
  input_pos = 0;
}
inline char next_char(bool advance = true) {
  if (input_pos >= input_len) _update_input_buffer();
  return input_buffer[advance ? input_pos++ : input_pos];
}
inline bool isspace(char c) {
  return (unsigned char)(c - '\t') < 5 || c == ' ';
}
template <typename T>
inline void read_int(T &number) {
  while (isspace(next_char(false))) next_char();
  bool negative = next_char(false) == '-';
  if (negative) next_char();
  number = 0;
  while (isdigit(next_char(false))) number = 10 * number + (next_char() - '0');
  if (negative) number = -number;
}
}  // namespace IO
const int N_MAX = 1e6 + 5;
const int BITS = 62;
long long N, K;
long long first[N_MAX], second[N_MAX];
long long A[N_MAX], B[N_MAX];
void flip_bit(int bit) {
  int a = 0, b = 0;
  for (int i = 0; i < N; i++)
    (second[i] & 1LL << bit ? A[a++] : B[b++]) = second[i] ^ 1LL << bit;
  merge(A, A + a, B, B + b, second);
}
long long starting_with(int low_bit) {
  long long total = 0;
  int pos = 0;
  for (int i = 0, j = 0; i < N; i = j) {
    j = i + 1;
    while (j < N && (first[i] >> low_bit) == (first[j] >> low_bit)) j++;
    while (pos < N && (second[pos] >> low_bit) <= (first[i] >> low_bit)) {
      if ((second[pos] >> low_bit) == (first[i] >> low_bit)) total += j - i;
      pos++;
    }
  }
  return total;
}
int main() {
  IO::read_int(N);
  IO::read_int(K);
  first[0] = 0;
  for (int i = 1; i < N; i++) {
    int parent;
    long long weight;
    IO::read_int(parent);
    IO::read_int(weight);
    first[i] = first[parent - 1] ^ weight;
  }
  sort(first, first + N);
  memcpy(second, first, sizeof(first));
  long long answer = 0;
  for (int bit = BITS - 1; bit >= 0; bit--) {
    long long count = starting_with(bit);
    if (K > count) {
      K -= count;
      answer += 1LL << bit;
      flip_bit(bit);
    }
  }
  printf("%lld\n", answer);
}
