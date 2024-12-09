#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair< int64, int64 > Pi;
const int64 INF = 1LL << 60;

Pi operator-(Pi &a, Pi &b)
{
  return {a.first - b.first, a.second - b.second};
}


int64 cross(Pi a, Pi b)
{
  return (a.first * b.second - b.first * a.second);
}

vector< int64 > beet(vector< Pi > point)
{
  auto f = [](vector< Pi > st)
  {

    vector< int64 > area(st.size(), 0);
    vector< Pi > upper;
    upper.emplace_back(st[0]);
    upper.emplace_back(st[1]);
    for(int i = 2; i < st.size(); i++) {
      area[i] += area[i - 1];
      while(upper.size() >= 2) {
        int sz = (int) upper.size();
        if(cross(upper[sz - 1] - upper[sz - 2], st[i] - upper[sz - 1]) >= 0) break;
        if(upper.size() > 2) area[i] -= cross(upper[upper.size() - 2] - upper[0], upper.back() - upper[0]);
        upper.pop_back();
      }
      upper.push_back(st[i]);
      if(upper.size() > 2) area[i] += cross(upper[upper.size() - 2] - upper[0], upper.back() - upper[0]);
    }
    return (area);
  };

  vector< int64 > latte(point.size(), 0LL);
  auto lala = f(point);
  for(int i = 0; i < point.size(); i++) point[i].second *= -1;
  auto rara = f(point);
  for(int i = 0; i < point.size(); i++) latte[i] += lala[i];
  for(int i = 0; i < point.size(); i++) latte[i] += rara[i];
  return (latte);
}

int main()
{
  int N;
  scanf("%d", &N);
  vector< Pi > P(N);
  for(auto &p : P) scanf("%lld %lld", &p.first, &p.second);
  sort(begin(P), end(P));
  auto pp = beet(P);
  reverse(begin(P), end(P));
  auto qq = beet(P);
  sort(begin(P), end(P));
  reverse(begin(qq), end(qq));
  int64 ret = min(pp.back(), qq.front());
  for(int i = 1; i < N; i++) {
    if(P[i - 1].first != P[i].first) ret = min(ret, pp[i - 1] + qq[i]);
  }
  printf("%lld\n", (ret + 1) / 2);
}