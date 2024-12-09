#include <bits/stdc++.h>

using namespace std;

template<int MOD>
struct ModInt {
   using Mint = ModInt;
   int val;
   ModInt(int64_t __val = 0) { fix(__val % MOD + MOD); }
   Mint& fix(int __val) { val = __val; if (val >= MOD) val -= MOD; return *this; }
   explicit operator int() { return val; }
   Mint operator + (const Mint &mt) const { return Mint().fix(val + mt.val); }
   Mint operator - (const Mint &mt) const { return Mint().fix(val - mt.val + MOD); }
   Mint operator * (const Mint &mt) const { return Mint().fix(int64_t(val) * mt.val % MOD + MOD); }
   Mint& operator += (const Mint &mt) { return *this = *this + mt; }
   Mint& operator -= (const Mint &mt) { return *this = *this - mt; }
   Mint& operator *= (const Mint &mt) { return *this = *this * mt; }
   Mint pow(int y) const {
      Mint x = *this;
      Mint ans(1);
      for (; y > 0; y >>= 1, x *= x) {
         if (y & 1) ans *= x;
      }
      return ans;
   }
   Mint operator -() const { return Mint().fix(MOD - val); }
   Mint inv() const { return pow(MOD - 2); }
   Mint operator / (const Mint &mt) const { return *this * mt.inv(); }
   Mint& operator /= (const Mint &mt) const { return *this / mt; }
   friend ostream& operator<<(ostream& os, const Mint& mt) { return os << mt.val; }
};

using Mint = ModInt<1000000007>;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, A, B, C; cin >> N >> A >> B >> C;
   if (B & 1) {
      cout << "0\n";
      return 0;
   }
   B >>= 1;
   vector<Mint> fact(N+1);
   fact[0] = 1; for (int i = 1; i <= N; ++i) fact[i] = fact[i - 1] * i;
   vector<Mint> ifact(N+1);
   ifact[N] = fact[N].inv(); for (int i = N; i > 0; --i) ifact[i - 1] = ifact[i] * i;
   Mint ans = 0;
   for (int x = 0; x <= min(A, C); ++x) {
      for (int y = 0; x + 3 * y <= C; ++y) {
         int z = C - x - 3 * y;
         Mint ways = (B == 0 ? Mint(!z) : fact[z + B - 1] * ifact[B - 1] * ifact[z]);
         ways *= fact[x + y + B + A - x] * ifact[x] * ifact[y] * ifact[B] * ifact[A - x];
         ans += ways;
      }
   }
   cout << ans << '\n';
   return 0;
}
