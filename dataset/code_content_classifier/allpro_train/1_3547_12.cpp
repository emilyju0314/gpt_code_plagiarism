#include <bits/stdc++.h>

using namespace std;

int N, K;
string S[16];
map< string, string > dp[1 << 16][16];

string check(int bit, int last, string used)
{
  if(bit == (1 << N) - 1) return ("");
  if(dp[bit][last].count(used)) return (dp[bit][last][used]);
  string beet = S[last];
  reverse(begin(beet), end(beet));
  beet += used;

  string ret = "~";
  for(int i = 0; i < N; i++) {
    if((bit >> i) & 1) continue;
    int tail = 0;
    string odd;
    for(int j = 0; j < beet.size(); j++) {
      if(tail < K && beet[j] == S[i][tail]) ++tail;
      else odd += beet[j];
    }
    if(tail == K) {
      auto get = check(bit | (1 << i), i, odd);
      if(get != "~") ret = min(ret, string(1, 'A' + i) + get);
    }
  }

  return (dp[bit][last][used] = ret);
}


int main()
{
  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }


  string ret = "~";
  for(int j = 0; j < N; j++) {

    bool used[26] = {};
    for(int i = 0; i < K; i++) {
      used[S[j][i] - 'A'] = true;
    }
    string rest;
    for(int i = 0; i < N; i++) {
      if(used[i]) continue;
      rest += (char) (i + 'A');
    }

    for(int i = 0; i < (1 << N); i++) {
      if(__builtin_popcount(i) != K) continue;
      do {
        string beet;
        int latte = 0, malta = 0;
        for(int k = 0; k < N; k++) {
          if((i >> k) & 1) beet += S[j][latte++];
          else beet += rest[malta++];
        }
        auto get = check(1 << j, j, rest);

        if(get != "~") {
          ret = min(ret, string(1, 'A' + j) + get);
        }
      } while(next_permutation(begin(rest), end(rest)));
    }
  }

  cout << ret << endl;
}