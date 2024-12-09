#include <bits/stdc++.h>
using namespace std;
int arr[50001], n, p, may;
vector<int> cuantos[3];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p);
    arr[p]++;
    may = max(may, p);
  }
  for (int i = 1; i < may; i++) {
    if (arr[i] == 1)
      cuantos[1].push_back(i);
    else if (arr[i] > 1)
      cuantos[2].push_back(i);
  }
  printf("%d\n", 1 + cuantos[1].size() + (2 * cuantos[2].size()));
  for (int i = 0; i < cuantos[2].size(); i++) printf("%d ", cuantos[2][i]);
  printf("%d", may);
  for (int i = 0; i < cuantos[1].size(); i++) arr[i] = cuantos[1][i];
  for (int i = 0; i < cuantos[2].size(); i++)
    arr[i + cuantos[1].size()] = cuantos[2][i];
  sort(arr, arr + cuantos[1].size() + cuantos[2].size());
  for (int i = cuantos[1].size() + cuantos[2].size() - 1; i > -1; i--)
    printf(" %d", arr[i]);
}
