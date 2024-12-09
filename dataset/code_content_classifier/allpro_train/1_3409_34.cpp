#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, K;
  cin >> N >> M >> K;
  int vet[M], aux, aux1;
  for (int i = 0; i < M; i++) vet[i] = 99999999;
  for (int i = 0; i < N; i++) {
    cin >> aux >> aux1;
    vet[aux - 1] = min(aux1, vet[aux - 1]);
  }
  int som = 0;
  for (int i = 0; i < M; i++) {
    som += vet[i];
  }
  cout << min(som, K);
  return 0;
}
