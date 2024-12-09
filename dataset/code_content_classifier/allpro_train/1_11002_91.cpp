#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
long long mod_1097(long long a) {
  long long mod_a;
  if (a > 1000000007) {
    mod_a = a % 1000000007;
    if (mod_a < 0) {
      mod_a += 1000000007;
    }
  } else {
    mod_a = a;
  }
  return mod_a;
}
long long calc_good(vector<long long>& a, int i, int b_length,
                    vector<map<int, int>>& cache) {
  if (cache[i].find(b_length) != cache[i].end()) {
    return cache[i][b_length];
  }
  long long good_count = 0;
  for (int j = i; j < a.size(); j++) {
    if ((a[j] % (b_length + 1)) == 0) {
      good_count += 1;
      good_count += calc_good(a, j + 1, b_length + 1, cache);
      good_count = mod_1097(good_count);
    }
  }
  cache[i][b_length] = good_count;
  return good_count;
}
vector<int> get_primes(long long n) {
  vector<int> primes = {1};
  vector<int> nums(n, 0);
  for (int i = 2; i < n; i++) {
    if (nums[i] == 0) {
      primes.push_back(i);
      for (int j = i * 2; j < n; j += i) {
        nums[j] = i;
      }
    }
  }
  return primes;
}
vector<long long> sieve(long long n) {
  vector<long long> res(n + 1, 0);
  res[n] = n;
  for (int i = 2; i < pow(n, 1 / 2); i++) {
    long long shuttle = i * i;
    while (shuttle < n) {
      res[shuttle] = i;
      shuttle += i;
    }
  }
  return res;
}
long long ceil_(long long a, long long b) {
  if (a % b == 0) {
    return a / b;
  } else {
    return a / b + 1;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  long long array_sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    array_sum += a[i];
  }
  map<long long, vector<long long>> sum_without_el;
  vector<long long> sum_without_el_arr(n);
  for (int i = 0; i < n; i++) {
    long long sum_wihout_i = array_sum - a[i];
    if (sum_without_el.find(sum_wihout_i) == sum_without_el.end()) {
      sum_without_el[sum_wihout_i] = vector<long long>();
    }
    sum_without_el[sum_wihout_i].push_back(i);
    sum_without_el_arr[i] = sum_wihout_i;
  }
  set<long long> res;
  for (int i = 0; i < n; i++) {
    if (sum_without_el.find(a[i] * 2) != sum_without_el.end()) {
      ;
      ;
      if (sum_without_el[a[i] * 2].size() == 1 &&
          sum_without_el[a[i] * 2][0] == i) {
        continue;
      }
      for (auto& res_index : sum_without_el[a[i] * 2]) {
        res.insert(res_index + 1);
      }
    }
  }
  cout << res.size() << endl;
  for (auto& res_val : res) {
    cout << res_val << " ";
  }
  return 0;
}
