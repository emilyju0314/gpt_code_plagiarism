#include <bits/stdc++.h>
using namespace std;
template <class T>
void print_array(T a[], int size) {
  for (int i = 0; i < size; i++) cout << a[i] << " ";
  cout << endl;
}
template <class T>
void print_array_v(T &a) {
  int size = a.size();
  for (int i = 0; i < size; i++) cout << a[i] << " ";
  cout << endl;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void remove(map<int, int> &second, int num) {
  if (second[num] == 1)
    second.erase(num);
  else
    second[num]--;
}
int main() {
  int n;
  int num;
  scanf("%d", &n);
  map<int, int> second;
  __typeof(second.begin()) it;
  vector<int> a;
  for (int i = 0; i < n * n; i++) {
    scanf("%d", &num);
    second[num]++;
  }
  for (int i = 0; i < n; i++) {
    it = second.end();
    it--;
    for (__typeof(a.begin()) it2(a.begin()); it2 != a.end(); it2++) {
      int x = gcd(*it2, it->first);
      remove(second, x);
      remove(second, x);
    }
    a.push_back(it->first);
    remove(second, it->first);
  }
  print_array_v(a);
  return 0;
}
