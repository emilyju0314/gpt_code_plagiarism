#include<bits/stdc++.h>

using namespace std;

struct CumulativeSum2D
{
  vector< vector< int > > data;

  CumulativeSum2D(int W, int H) : data(W + 1, vector< int >(H + 1, 0))
  {
  };

  inline void add(int x, int y, int z)
  {
    ++x, ++y;
    if(x >= data.size() || y >= data[0].size()) return;
    data[x][y] += z;
  }

  void build()
  {
    for(int i = 1; i < data.size(); i++) {
      for(int j = 1; j < data[i].size(); j++) {
        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
      }
    }
  }

  inline int query(int sx, int sy, int gx, int gy)
  {
    return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
  }
};

int main()
{
  int N, M, X[5000], Y[5000];

  scanf("%d %d", &N, &M);
  vector< int > xs, ys;
  for(int i = 0; i < N; i++) {
    scanf("%d %d", &X[i], &Y[i]);
    xs.push_back(X[i]);
    ys.push_back(Y[i]);
  }
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  sort(begin(ys), end(ys));
  ys.erase(unique(begin(ys), end(ys)), end(ys));
  CumulativeSum2D sum(xs.size(), ys.size());
  for(int i = 0; i < N; i++) {
    sum.add(lower_bound(begin(xs), end(xs), X[i]) - begin(xs),
            lower_bound(begin(ys), end(ys), Y[i]) - begin(ys), 1);
  }
  sum.build();
  for(int i = 0; i < M; i++) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1 = lower_bound(begin(xs), end(xs), x1) - begin(xs);
    y1 = lower_bound(begin(ys), end(ys), y1) - begin(ys);
    x2 = upper_bound(begin(xs), end(xs), x2) - begin(xs);
    y2 = upper_bound(begin(ys), end(ys), y2) - begin(ys);
    printf("%d\n", sum.query(x1, y1, x2, y2));
  }
}