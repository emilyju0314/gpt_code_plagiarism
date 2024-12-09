#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long int n) {
  if (n == 1) return false;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void storeUsefulPrimes(
    long long int k, vector<long long int> &usefulPrimes,
    unordered_map<long long int, long long int> &primesFrequencyK) {
  if (isPrime(k)) {
    usefulPrimes.push_back(k);
    primesFrequencyK[k] = 1;
    return;
  }
  long long int p = 2;
  while (k > 1) {
    long long int count = 0;
    while (k % p == 0) {
      k /= p;
      count++;
    }
    if (count) {
      usefulPrimes.push_back(p);
      primesFrequencyK[p] = count;
    }
    p++;
  }
}
void addPrime(unordered_map<long long int, long long int> &primesFrequency,
              vector<long long int> &usefulPrimes, int n) {
  for (long long int p : usefulPrimes) {
    long long int count = 0;
    while (n % p == 0) {
      n /= p;
      count++;
    }
    primesFrequency[p] += count;
  }
}
void removePrime(unordered_map<long long int, long long int> &primesFrequency,
                 vector<long long int> &usefulPrimes, int n) {
  for (long long int p : usefulPrimes) {
    long long int count = 0;
    while (n % p == 0) {
      n /= p;
      count++;
    }
    primesFrequency[p] -= count;
  }
}
bool isAtleast(unordered_map<long long int, long long int> &m1,
               unordered_map<long long int, long long int> &m2) {
  for (auto it = m2.begin(); it != m2.end(); it++) {
    long long int key = it->first, value = it->second;
    if (m1.find(key) == m1.end() or m1[key] < value) return false;
  }
  return true;
}
long long int solve(long long int arr[], long long int n, long long int k) {
  vector<long long int> usefulPrimes;
  unordered_map<long long int, long long int> primesFrequencyK,
      primesFrequencyWindow;
  storeUsefulPrimes(k, usefulPrimes, primesFrequencyK);
  long long int i = 0, j = 0, count = 0;
  while (j < n) {
    addPrime(primesFrequencyWindow, usefulPrimes, arr[j]);
    while (i <= j and isAtleast(primesFrequencyWindow, primesFrequencyK)) {
      count += (n - j);
      removePrime(primesFrequencyWindow, usefulPrimes, arr[i]);
      i++;
    }
    j++;
  }
  return count;
}
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  long long int ans = solve(arr, n, k);
  cout << ans;
  return 0;
}
