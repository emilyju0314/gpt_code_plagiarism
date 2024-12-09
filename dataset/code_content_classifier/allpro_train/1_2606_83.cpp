#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int arr[n];
  int menor = 0;
  int soma = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] < arr[menor]) menor = i;
    soma += arr[i];
  }
  int ans = soma;
  for (int i = 2; i <= 50; i++) {
    int maior = -1;
    for (int j = 0; j < n; j++) {
      if (arr[j] % i == 0 && (maior == -1 || arr[j] > arr[maior])) maior = j;
    }
    if (maior == -1) continue;
    int soma2 = soma;
    soma2 -= arr[maior];
    soma2 -= arr[menor];
    soma2 += arr[maior] / i;
    soma2 += arr[menor] * i;
    ans = min(ans, soma2);
  }
  cout << ans << endl;
}
