#include <bits/stdc++.h>
using namespace std;
struct genre {
  int genreQuantity = 0;
};
int main() {
  int n, m, temp;
  vector<int> sequenceGenre;
  vector<genre> listGenre;
  cin >> n >> m;
  genre t1;
  for (int i = 0; i < n; i++) {
    listGenre.push_back(t1);
  }
  for (int i = 0; i < n; i++) {
    cin >> temp;
    sequenceGenre.push_back(temp);
    listGenre[temp - 1].genreQuantity++;
  }
  int count = 0, sum = n, del = 0;
  for (int i = 0; i < m; i++) {
    del += listGenre[i].genreQuantity;
    count += (sum - del) * listGenre[i].genreQuantity;
  }
  cout << count;
  return 0;
}
