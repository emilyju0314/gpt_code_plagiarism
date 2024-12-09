#include <bits/stdc++.h>
using uint = unsigned int;
constexpr uint MaxL(100000u);
constexpr unsigned short SIGMA(6u);
constexpr unsigned short FULL_STATE((1u << 6u) - 1u);
namespace IOManager {
constexpr uint FILESZ(1500010u);
unsigned char buf[FILESZ];
const unsigned char *ibuf = buf;
struct IOManager {
  IOManager() { buf[fread(buf, 1u, FILESZ, stdin)] = ' '; }
  ~IOManager() {}
  template <class _Tp>
  inline operator _Tp() {
    _Tp s = 0u;
    for (; !isdigit(*ibuf); ++ibuf)
      ;
    for (; isdigit(*ibuf); ++ibuf) s = (_Tp)(s * 10u + *ibuf - 48u);
    return s;
  }
  template <class _Tp>
  inline _Tp operator()(_Tp &rhs) {
    _Tp s = 0u;
    for (; !isdigit(*ibuf); ++ibuf)
      ;
    for (; isdigit(*ibuf); ++ibuf) s = (_Tp)(s * 10u + *ibuf - 48u);
    return rhs = s;
  }
  inline uint operator()(unsigned char *const &str) {
    unsigned char *s = str;
    for (; isspace(*ibuf); ++ibuf)
      ;
    for (; !isspace(*ibuf);) *s++ = *ibuf++;
    return *s = 0u, s - str;
  }
  inline uint operator()(char *str) { return (*this)((unsigned char *)str); }
  inline uint operator()(const char *str) {
    return (*this)((unsigned char *)str);
  }
  inline uint operator()(const unsigned char *str) {
    return (*this)((unsigned char *)str);
  }
};
}  // namespace IOManager
IOManager::IOManager io;
using IOManager::ibuf;
unsigned char s[MaxL + 1u];
unsigned short vaild[MaxL + 1u];
unsigned short lg2[64u];
uint cnts[6u];
uint cntv[64u];
uint cntsum[64u];
inline bool chk() {
  for (uint i = 1u; i <= 63u; ++i)
    if ((cntsum[i] = cntsum[i ^ (i & -i)] + cnts[lg2[i & -i]]) + cntv[i ^ 63u] >
        cntv[63u])
      return false;
  return true;
}
int main() {
  lg2[1u] = 0u;
  lg2[2u] = 1u;
  lg2[4u] = 2u;
  lg2[8u] = 3u;
  lg2[16u] = 4u;
  lg2[32u] = 5u;
  const uint n = io(s + 1u);
  for (uint i = 1u; i <= n; ++i) vaild[i] = 63u;
  for (uint pos, m = io; m; --m) {
    for (vaild[pos = io] = 0u; isspace(*ibuf); ++ibuf)
      ;
    for (; !isspace(*ibuf);) vaild[pos] |= (1u << ((*ibuf++) - 97u));
  }
  for (uint i = 1u; i <= n; ++i) ++cnts[s[i] - 97u], ++cntv[vaild[i]];
  for (uint i = 0u; i < 6u; ++i)
    for (uint j = 0u; j <= 63u; ++j)
      if ((j >> i) & 1u) cntv[j] += cntv[j ^ (1u << i)];
  if (!chk()) return puts("Impossible"), 0;
  unsigned char *Ans = s;
  for (uint i = 1u; i <= n; ++i) {
    for (uint j = vaild[i]; j != 63u; j = (j + 1u) | vaild[i]) --cntv[j];
    --cntv[63u];
    for (unsigned short c = 0u; c < 6u; ++c)
      if ((vaild[i] >> c) & 1u) {
        --cnts[c];
        if (chk()) {
          *++Ans = c + 97u;
          break;
        }
        ++cnts[c];
      }
  }
  fwrite(s + 1u, 1u, n, stdout);
  return 0;
}
