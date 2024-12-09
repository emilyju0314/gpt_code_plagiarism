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
   int N; cin >> N; N /= 3;
   vector<int> A(3*N);
   vector<int> B(3*N);
   vector<int> invA(3*N);
   vector<int> invB(3*N);
   for (int i = 0; i < 3*N; ++i) cin >> A[i], invA[--A[i]] = i;
   for (int i = 0; i < 3*N; ++i) cin >> B[i], invB[--B[i]] = i;
   vector<vector<Mint>> ways(N+1, vector<Mint>(2*N+1));
   ways[0][0] = 1;
   for (int i = 0; i <= N; ++i) {
      for (int j = 2*i; j >= 0; --j) {
         if (i < N) ways[i+1][j+2] += ways[i][j];
         if (j) ways[i][j-1] += ways[i][j] * j;
      }
   }
   vector<vector<bool>> isGood(3*N, vector<bool>(3*N));
   vector<vector<int>> cnts(3*N, vector<int>(3*N));
   for (int i = 0; i < 3*N; ++i) {
      for (int j = 0; j < 3*N; ++j) {
         isGood[i][j] = (invB[A[i]] > j && invA[B[j]] > i);
         for (int z = 0; z < 3*N; ++z) if (invA[z] <= i || invB[z] <= j) cnts[i][j]++;
      }
   }
   vector<vector<Mint>> dp(3*N, vector<Mint>(3*N));
   for (int z = N-1; z >= 0; --z) {
      vector<vector<Mint>> ndp(3*N, vector<Mint>(3*N));
      for (int i = 0; i < 3*N; ++i) {
         for (int j = 0; j < 3*N; ++j) if (isGood[i][j]) {
            ndp[i][j] = 3*N - (N-1-z) * 3 - cnts[i][j];
            if (z < N-1) {
               if (i == 3*N-1 || j == 3*N-1) ndp[i][j] = 0;
               else ndp[i][j] *= dp[i+1][j+1];
            }
         }
      }
      dp.swap(ndp);
      for (int i = 3*N-1; i >= 0; --i) {
         for (int j = 3*N-1; j >= 0; --j) {
            if (i+1 < 3*N) dp[i][j] += dp[i+1][j];
            if (j+1 < 3*N) dp[i][j] += dp[i][j+1];
            if (i+1 < 3 * N && j+1 < 3*N) dp[i][j] -= dp[i+1][j+1];
         }
      }
   }
   cout << dp[0][0] * ways[N][0] << '\n';
   return 0;
}
