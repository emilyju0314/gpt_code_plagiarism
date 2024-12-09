#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int maxn = 1000000;
int dpi[maxn], dpf[maxn];
int cpi[maxn], cpf[maxn];
vector<string> words;
string s;
template <class T>
void allset(T a[], int v, int n) {
  for (int i = 0; i < n; i++) a[i] = v;
}
void Update_I(string a, string b, int dp[], int dp_2[]) {
  int m = a.size(), n = b.size();
  int N = max(m, n);
  int nextUnequal[N];
  int pos = N - 1;
  for (int i = N - 1; i >= 0; i--) {
    if ((i >= min(m - 1, n)) || (a[i + 1] != b[i])) pos = i;
    nextUnequal[i] = pos;
  }
  bool compRight[N];
  for (int i = N - 1; i >= 0; i--) {
    if ((i + 1) >= m)
      compRight[i] = true;
    else if (i >= n)
      compRight[i] = false;
    else {
      if (a[i + 1] > b[i])
        compRight[i] = false;
      else if (a[i + 1] < b[i])
        compRight[i] = true;
      else
        compRight[i] = compRight[i + 1];
    }
  }
  bool compSuffix[N];
  for (int i = N - 1; i >= 0; i--) {
    if ((i + 1) >= m)
      compSuffix[i] = true;
    else if ((i + 1) >= n)
      compSuffix[i] = false;
    else {
      if (a[i + 1] > b[i + 1])
        compSuffix[i] = false;
      else if (a[i + 1] < b[i + 1])
        compSuffix[i] = true;
      else
        compSuffix[i] = compSuffix[i + 1];
    }
  }
  int suffixCompDiffs[N], simpleDiffs[N];
  allset<int>(suffixCompDiffs, 0, N), allset<int>(simpleDiffs, 0, N);
  int prefixComp = 0;
  for (int s = 0; s < m; s++) {
    if (prefixComp == 0) {
      int i = nextUnequal[s];
      if (((i + 1) < N) && compRight[i])
        simpleDiffs[i + 1] =
            ((long long int)simpleDiffs[i + 1] + (long long int)dp[s]) % M;
      suffixCompDiffs[s] =
          ((long long int)suffixCompDiffs[s] + (long long int)dp[s]) % M;
      if ((i + 1) < N)
        suffixCompDiffs[i + 1] = ((long long int)suffixCompDiffs[i + 1] +
                                  (long long int)M - (long long int)dp[s]) %
                                 M;
    } else if (prefixComp == 1)
      simpleDiffs[s] =
          ((long long int)simpleDiffs[s] + (long long int)dp[s]) % M;
    if (prefixComp == 0) {
      if ((s >= n) || (a[s] > b[s]))
        prefixComp = -1;
      else if (a[s] < b[s])
        prefixComp = 1;
    }
  }
  int simpleSum = 0, suffixCompSum = 0;
  for (int i = 0; i < n; i++) {
    simpleSum = ((long long int)simpleSum + (long long int)simpleDiffs[i]) % M;
    suffixCompSum =
        ((long long int)suffixCompSum + (long long int)suffixCompDiffs[i]) % M;
    dp_2[i] = ((long long int)dp_2[i] + (long long int)simpleSum +
               (long long int)suffixCompSum * compSuffix[i]) %
              M;
  }
}
void Update_II(string a, string b, int dp[], int dp_2[]) {
  int m = a.size(), n = b.size();
  int N = max(m, n);
  int nextUnequal[N];
  int pos = N - 1;
  for (int i = N - 1; i >= 0; i--) {
    if ((i >= min(n - 1, m)) || (a[i] != b[i + 1])) pos = i;
    nextUnequal[i] = pos;
  }
  bool compLeft[N];
  for (int i = N - 1; i >= 0; i--) {
    if (i >= m)
      compLeft[i] = true;
    else if ((i + 1) >= n)
      compLeft[i] = false;
    else {
      if (a[i] < b[i + 1])
        compLeft[i] = true;
      else if (a[i] > b[i + 1])
        compLeft[i] = false;
      else
        compLeft[i] = compLeft[i + 1];
    }
  }
  bool compSuffix[N];
  for (int i = N - 1; i >= 0; i--) {
    if ((i + 1) >= m)
      compSuffix[i] = true;
    else if ((i + 1) >= n)
      compSuffix[i] = false;
    else {
      if (a[i + 1] > b[i + 1])
        compSuffix[i] = false;
      else if (a[i + 1] < b[i + 1])
        compSuffix[i] = true;
      else
        compSuffix[i] = compSuffix[i + 1];
    }
  }
  int suffixSum[N + 1], suffixCompSum[N + 1];
  allset<int>(suffixCompSum, 0, N), allset<int>(suffixSum, 0, N);
  suffixSum[N] = 0, suffixCompSum[N] = 0;
  for (int i = N - 1; i >= 0; i--) {
    suffixSum[i] = ((long long int)suffixSum[i + 1] +
                    (long long int)((i < m) ? dp[i] : 0)) %
                   M;
    suffixCompSum[i] =
        ((long long int)suffixCompSum[i + 1] +
         (long long int)(((i < m) && compSuffix[i]) ? dp[i] : 0)) %
        M;
  }
  int prefixComp = 0;
  for (int t = 0; t < n; t++) {
    if (prefixComp == 0) {
      int j = nextUnequal[t];
      if (compLeft[j])
        dp_2[t] = ((long long int)dp_2[t] +
                   (long long int)(((j + 1) < N) ? suffixSum[j + 1] : 0)) %
                  M;
      if ((t + 1) < N)
        dp_2[t] =
            ((long long int)dp_2[t] + (long long int)suffixCompSum[t + 1]) % M;
      if ((j + 1) < N)
        dp_2[t] = ((long long int)dp_2[t] + (long long int)M -
                   (long long int)suffixCompSum[j + 1]) %
                  M;
    } else if (prefixComp == 1)
      if ((t + 1) < N)
        dp_2[t] =
            ((long long int)dp_2[t] + (long long int)suffixSum[t + 1]) % M;
    if (prefixComp == 0) {
      if ((t >= m) || (a[t] < b[t]))
        prefixComp = 1;
      else if (a[t] > b[t])
        prefixComp = -1;
    }
  }
}
void Update_III(string a, string b, int dp[], int dp_2[]) {
  string a_original = a;
  a = a.substr(1, a.size() - 1);
  int m = a.size(), n = b.size();
  int N = max(m, n);
  stack<pair<int, int> > unequalPositions;
  for (int i = N - 1; i >= 0; i--) {
    if (i >= m)
      unequalPositions.push(make_pair(i, 1));
    else if (i >= n)
      unequalPositions.push(make_pair(i, -1));
    else {
      if (a[i] > b[i]) unequalPositions.push(make_pair(i, -1));
      if (a[i] < b[i]) unequalPositions.push(make_pair(i, 1));
    }
  }
  for (int i = 0; i < m; i++) {
    if (unequalPositions.empty() || (unequalPositions.top().second == 1))
      dp_2[n] = ((long long int)dp_2[n] + (long long int)dp[i]) % M;
    a[i] = a_original[i];
    if (!unequalPositions.empty() && (unequalPositions.top().first == i))
      unequalPositions.pop();
    if ((i >= n) || (a[i] != b[i])) {
      if (unequalPositions.empty() || (unequalPositions.top().first > i))
        unequalPositions.push(
            make_pair(i, ((i >= n) || (a[i] > b[i])) ? -1 : 1));
    }
  }
  if (unequalPositions.empty() || (unequalPositions.top().second == 1))
    dp_2[n] = ((long long int)dp_2[n] + (long long int)dp[m]) % M;
  a = a_original;
  string b_original = b;
  b = b.substr(1, b.size() - 1);
  m = a.size(), n = b.size();
  N = max(m, n);
  while (!unequalPositions.empty()) unequalPositions.pop();
  for (int i = N - 1; i >= 0; i--) {
    if (i >= m)
      unequalPositions.push(make_pair(i, 1));
    else if (i >= n)
      unequalPositions.push(make_pair(i, -1));
    else {
      if (a[i] > b[i])
        unequalPositions.push(make_pair(i, -1));
      else if (a[i] < b[i])
        unequalPositions.push(make_pair(i, 1));
    }
  }
  for (int i = 0; i < n; i++) {
    if (unequalPositions.empty() || (unequalPositions.top().second == 1))
      dp_2[i] = ((long long int)dp_2[i] + (long long int)dp[m]) % M;
    b[i] = b_original[i];
    if (!unequalPositions.empty() && (unequalPositions.top().first == i))
      unequalPositions.pop();
    if ((i >= m) || (a[i] != b[i])) {
      if (unequalPositions.empty() || (unequalPositions.top().first > i))
        unequalPositions.push(
            make_pair(i, ((i >= m) || (a[i] < b[i])) ? 1 : -1));
    }
  }
  if (unequalPositions.empty() || (unequalPositions.top().second == 1))
    dp_2[n] = ((long long int)dp_2[n] + (long long int)dp[m]) % M;
  b = b_original;
  m = a.size(), n = b.size();
  if (strcmp(a.c_str(), b.c_str()) <= 0)
    dp_2[n] = ((long long int)dp_2[n] + (long long int)dp[m]) % M;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    words.push_back(s);
  }
  allset<int>(dpi, 0, maxn), allset<int>(dpf, 0, maxn);
  allset<int>(dpi, 1, (int)words[0].size() + 1);
  for (int i = 0; i < n - 1; i++) {
    int m = words[i].size(), n = words[i + 1].size();
    Update_I(words[i], words[i + 1], dpi, dpf);
    Update_II(words[i], words[i + 1], dpi, dpf);
    Update_III(words[i], words[i + 1], dpi, dpf);
    allset<int>(dpi, 0, m + 1);
    for (int i = 0; i <= n; i++) dpi[i] = dpf[i];
    allset<int>(dpf, 0, n + 1);
  }
  long long int total = 0;
  for (int i = 0; i < words.back().size() + 1; i++)
    total = (total + dpi[i]) % M;
  cout << total << endl;
}
