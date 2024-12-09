#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

namespace FastFourierTransform
{
  using C = complex< double >;

  void DiscreteFourierTransform(vector< C > &F, bool rev)
  {
    const int N = (int) F.size();
    const double PI = (rev ? -1 : 1) * acos(-1);
    for(int i = 0, j = 1; j + 1 < N; j++) {
      for(int k = N >> 1; k > (i ^= k); k >>= 1);
      if(i > j) swap(F[i], F[j]);
    }
    C w, s, t;
    for(int i = 1; i < N; i <<= 1) {
      for(int k = 0; k < i; k++) {
        w = std::polar(1.0, PI / i * k);
        for(int j = 0; j < N; j += i * 2) {
          s = F[j + k];
          t = C(F[j + k + i].real() * w.real() - F[j + k + i].imag() * w.imag(), F[j + k + i].real() * w.imag() + F[j + k + i].imag() * w.real());
          F[j + k] = s + t, F[j + k + i] = s - t;
        }
      }
    }
    if(rev) {
      double temp = 1.0 / N;
      for(int i = 0; i < N; i++) F[i] *= temp;
    }
  }

  vector< long long > Multiply(const vector< int > &A, const vector< int > &B)
  {
    int sz = 1;
    while(sz <= A.size() + B.size()) sz <<= 1;
    vector< C > F(sz), G(sz);
    for(int i = 0; i < A.size(); i++) F[i] = A[i];
    for(int i = 0; i < B.size(); i++) G[i] = B[i];
    DiscreteFourierTransform(F, false);
    DiscreteFourierTransform(G, false);
    for(int i = 0; i < sz; i++) F[i] *= G[i];
    DiscreteFourierTransform(F, true);
    vector< long long > X(A.size() + B.size() - 1);
    for(int i = 0; i < A.size() + B.size() - 1; i++) X[i] = F[i].real() + 0.5;
    return (X);
  }
};

int main()
{
  int N, M, Q, A[40001], B[40001], C[100000];
  vector< int > F(200001), G(200001);

  scanf("%d %d %d", &N, &M, &Q);
  for(int i = 0; i < N; i++) scanf("%d", &A[i + 1]), A[i + 1] += A[i];
  for(int i = 0; i < M; i++) scanf("%d", &B[i + 1]), B[i + 1] += B[i];
  for(int i = 0; i < Q; i++) scanf("%d", &C[i]);

  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < i; j++) {
      ++F[A[i] - A[j]];
    }
  }
  for(int i = 1; i <= M; i++) {
    for(int j = 0; j < i; j++) {
      ++G[B[i] - B[j]];
    }
  }
  reverse(begin(G), end(G));
  auto X = FastFourierTransform::Multiply(F, G);
  for(int i = 0; i < Q; i++) {
    if(C[i] == 0) printf("%lld\n", X[200000]);
    else printf("%lld\n", X[200000 - C[i]] + X[200000 + C[i]]);
  }
}