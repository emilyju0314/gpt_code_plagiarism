#include <bits/stdc++.h>
template <typename T>
std::istream& operator>>(std::istream& input, std::vector<T>& v) {
  for (T& a : v) input >> a;
  return input;
}
void answer(unsigned v) { std::cout << v << '\n'; }
void solve(const std::vector<std::vector<unsigned>>& a) {
  const auto check = [&](unsigned x) {
    std::vector<std::vector<unsigned>> b = a;
    std::sort(b.begin(), b.end());
    const size_t n = b.size();
    do {
      unsigned q = x;
      for (size_t i = 0; i < n && q != 0; ++i) {
        if (std::find(b[i].cbegin(), b[i].cend(), q % 10) == b[i].cend()) break;
        q /= 10;
      }
      if (q == 0) return true;
    } while (std::next_permutation(b.begin(), b.end()));
    return false;
  };
  unsigned x = 0;
  while (check(x + 1)) ++x;
  answer(x);
}
int main() {
  size_t n;
  std::cin >> n;
  std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(6));
  std::cin >> a;
  solve(a);
  return 0;
}
