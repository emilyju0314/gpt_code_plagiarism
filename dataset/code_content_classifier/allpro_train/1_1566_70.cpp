#include <bits/stdc++.h>
int main() {
  unsigned int q;
  unsigned int ans = 0;
  unsigned long long sum[29] = {0};
  std::priority_queue<unsigned int, std::vector<unsigned int>,
                      std::greater<unsigned int>>
      dat[29], del[29];
  scanf("%u", &q);
  while (q--) {
    unsigned char op;
    unsigned int x;
    scanf(" %c %u", &op, &x);
    unsigned int p = 30 - __builtin_clz(x + 1);
    if (op == '+') {
      if (!dat[p].empty() && dat[p].top() > sum[p]) {
        ++ans;
      }
      dat[p].push(x);
      if (dat[p].top() <= sum[p]) {
        ++ans;
      }
      for (p++; p < 29; p++) {
        unsigned long long tmp = sum[p];
        sum[p] += x << 1;
        if (!dat[p].empty() && dat[p].top() > tmp && dat[p].top() <= sum[p]) {
          ++ans;
        }
      }
    } else {
      if (dat[p].empty() || dat[p].top() <= sum[p]) {
        --ans;
      }
      del[p].push(x);
      while (!del[p].empty() && del[p].top() == dat[p].top()) {
        dat[p].pop();
        del[p].pop();
      }
      if (!dat[p].empty() && dat[p].top() > sum[p]) {
        --ans;
      }
      for (p++; p < 29; p++) {
        unsigned long long tmp = sum[p];
        sum[p] -= x << 1;
        if (!dat[p].empty() && dat[p].top() <= tmp && dat[p].top() > sum[p]) {
          --ans;
        }
      }
    }
    printf("%u\n", ans);
  }
  return 0;
}
