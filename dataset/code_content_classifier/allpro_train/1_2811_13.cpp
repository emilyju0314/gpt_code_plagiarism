#include <bits/stdc++.h>
using namespace std;
int printArray(vector<int> vec, int n);
int AreAll9s(vector<int> vec, int n);
vector<int> generateNextPalindromeUtil(vector<int> num, int n) {
  int mid = n / 2;
  bool leftsmaller = false;
  int i = mid - 1;
  int j = (n % 2) ? mid + 1 : mid;
  while (i >= 0 && num[i] == num[j]) i--, j++;
  if (i < 0 || num[i] < num[j]) leftsmaller = true;
  while (i >= 0) {
    num[j] = num[i];
    j++;
    i--;
  }
  if (leftsmaller == true) {
    int carry = 1;
    i = mid - 1;
    if (n % 2 == 1) {
      num[mid] += carry;
      carry = num[mid] / 10;
      num[mid] %= 10;
      j = mid + 1;
    } else
      j = mid;
    while (i >= 0) {
      num[i] += carry;
      carry = num[i] / 10;
      num[i] %= 10;
      num[j++] = num[i--];
    }
  }
  return num;
}
int generateNextPalindrome(vector<int> num, int n) {
  int x;
  if (AreAll9s(num, n)) {
    x = 1;
    while (n-- > 0) x *= 10;
    x++;
  } else {
    num = generateNextPalindromeUtil(num, n);
    x = printArray(num, n);
  }
  return x;
}
int AreAll9s(vector<int> num, int n) {
  int i;
  for (i = 0; i < n; ++i)
    if (num[i] != 9) return 0;
  return 1;
}
int printArray(vector<int> arr, int n) {
  int i, x = 0;
  for (i = 0; i < n; i++) {
    x = x * 10 + arr[i];
  }
  return x;
}
vector<int> toVec(int num) {
  vector<int> vec;
  if (num == 0) vec.push_back(0);
  while (num > 0) {
    vec.push_back(num % 10);
    num /= 10;
  }
  reverse(vec.begin(), vec.end());
  return vec;
}
int p, q, data[10000003];
bool compo[10000003];
void pre(void) {
  int i, j, k;
  for (i = 2; i <= sqrt(10000003) + 1; i++) {
    if (compo[i]) continue;
    for (j = 2; i * j < 10000003; j++) {
      compo[i * j] = 1;
    }
  }
  for (i = 2; i <= 10000000; i++) {
    if (!compo[i])
      data[i] = data[i - 1] + 1;
    else
      data[i] = data[i - 1];
  }
}
bool checkIfTrue(int pi, int r) {
  long long pi_n = pi;
  long long r_n = r;
  if (pi_n * q <= r_n * p) return true;
  return false;
}
int main() {
  int i, j, n, ans;
  cin >> p >> q;
  pre();
  int N = 1;
  int c = 1, r_n = 1;
  while (N < 10000000) {
    vector<int> vec = toVec(N);
    int n = vec.size();
    if (checkIfTrue(data[N], c)) {
      ans = N;
      r_n = c;
    }
    N = generateNextPalindrome(vec, n);
    c++;
  }
  vector<int> vec = toVec(ans);
  int x = generateNextPalindrome(vec, vec.size());
  while (ans < x && checkIfTrue(data[ans], r_n)) ans++;
  cout << (ans - 1) << endl;
  return 0;
}
