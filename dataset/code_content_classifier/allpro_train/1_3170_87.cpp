#include <bits/stdc++.h>
struct Range {
  struct It {
    int num, step;
    int operator*() { return num; }
    void operator++() { num += step; }
    bool operator!=(const It& other) { return num != other.num; }
  };
  Range(int ee) : b(0), e(ee) {}
  Range(int bb, int ee) : b(bb), e(ee) {}
  It begin() { return {b, (b < e ? 1 : -1)}; }
  It end() { return {e, 0}; }
  int b, e;
};
template <typename T>
inline T& UMAX(T& x, T y) {
  if (x < y) x = y;
  return x;
}
template <typename T>
inline T& UMIN(T& x, T y) {
  if (y < x) x = y;
  return x;
}
template <typename T, typename... Args>
struct ArithmiticPromotion {
  typedef decltype(T() + typename ArithmiticPromotion<Args...>::type()) type;
};
template <typename T, typename U>
struct ArithmiticPromotion<T, U> {
  typedef decltype(T() + U()) type;
};
template <typename T>
struct ArithmiticPromotion<T, T> {};
template <typename T>
struct ArithmiticPromotion<T> {};
template <typename T, typename U>
typename ArithmiticPromotion<T, U>::T MAX(T a, U b) {
  return a < b ? b : a;
}
template <typename T, typename... Args>
typename ArithmiticPromotion<T, Args...>::T MAX(T a, Args... args) {
  return MAX(a, MAX(args...));
}
template <typename T, typename U>
typename ArithmiticPromotion<T, U>::T MIN(T a, U b) {
  return a < b ? a : b;
}
template <typename T, typename... Args>
typename ArithmiticPromotion<T, Args...>::T MIN(T a, Args... args) {
  return MIN(a, MIN(args...));
}
template <typename T>
struct ScanfSpecifier {};
template <>
struct ScanfSpecifier<char*> {
  static constexpr const char* value = "%s";
};
template <>
struct ScanfSpecifier<int> {
  static constexpr const char* value = "%d";
};
template <>
struct ScanfSpecifier<double> {
  static constexpr const char* value = "%lf";
};
template <>
struct ScanfSpecifier<float> {
  static constexpr const char* value = "%f";
};
template <>
struct ScanfSpecifier<char> {
  static constexpr const char* value = "%c";
};
template <>
struct ScanfSpecifier<const char*> {
  static constexpr const char* value = "%s";
};
template <>
struct ScanfSpecifier<unsigned long> {
  static constexpr const char* value = "%lu";
};
template <>
struct ScanfSpecifier<unsigned int> {
  static constexpr const char* value = "%u";
};
template <>
struct ScanfSpecifier<long long int> {
  static constexpr const char* value = "%lld";
};
template <typename T>
int RD(T& arg) {
  return std::scanf(ScanfSpecifier<T>::value, &arg);
}
template <int S>
int RD(char (&arg)[S]) {
  return std::scanf("%s", arg);
}
int RD(char* arg) { return std::scanf("%s", arg); }
template <>
int RD<char>(char& arg) {
  return std::scanf(" %c", &arg);
}
template <typename T, typename... Args>
int RD(T& arg1, Args&... args) {
  return RD(arg1) + RD(args...);
}
template <typename T>
T RD() {
  T ret;
  RD(ret);
  return ret;
}
template <typename It>
void RDV(It begin, It end) {
  while (begin != end) RD(*begin++);
}
template <typename C>
void RDV(C& c) {
  RDV(std::begin(c), std::end(c));
}
template <typename T>
void WT(T arg) {
  std::printf(ScanfSpecifier<T>::value, arg);
}
template <typename T, typename U>
void WT(std::pair<T, U> arg) {
  std::printf("(");
  WT(arg.first);
  std::printf(", ");
  WT(arg.second);
  std::printf(")");
}
template <typename... Args>
void WT(Args... args) {
  int alc = 0;
  int dummy[] = {((alc++ ? std::printf(" ") : 0), WT(args), 0)...};
}
template <typename... Args>
void WTL(Args... args) {
  WT(args...);
  std::printf("\n");
}
template <typename It>
void WTV(It begin, It end) {
  int alc = 0;
  while (begin != end) (alc++ ? std::printf(" ") : 0), WT(*begin++);
}
template <typename C>
void WTV(const C& c) {
  WTV(std::begin(c), std::end(c));
}
template <typename It>
void WTVL(It begin, It end) {
  WTV(begin, end);
  std::printf("\n");
}
template <typename C>
void WTVL(const C& c) {
  WTVL(std::begin(c), std::end(c));
}
using RG = Range;
using namespace std;
long long int v[1234][16];
int main() {
  int N;
  RD(N);
  for (int i : RG(N)) RDV(v[i], v[i] + 5);
  if (N <= 20) {
    vector<int> ans;
    for (int i : RG(N)) {
      bool check = true;
      for (int j : RG(N))
        if (j != i)
          for (int k : RG(N))
            if (k != i && k != j) {
              long long int alc = 0;
              for (int l : RG(5))
                alc += (v[j][l] - v[i][l]) * 1ll * (v[k][l] - v[i][l]);
              if (alc > 0) check = false;
            }
      if (check) ans.push_back(i + 1);
    }
    WTL(ans.size());
    if (ans.size()) WTVL(ans);
  } else {
    WTL(0);
  }
}
