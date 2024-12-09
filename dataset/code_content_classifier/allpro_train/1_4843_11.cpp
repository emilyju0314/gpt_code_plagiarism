#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
  int w, v;
  double vdw;
} Goods;

class GreaterVDW
{
public:
  bool operator() (const Goods& lhs, const Goods& rhs)
  {
    return lhs.vdw > rhs.vdw;
  }
};

int main()
{
  int N, W;
  while (cin >> N >> W) {
    double ans = 0.0;
    vector<Goods> goods;
    goods.reserve(N);
    for (int i = 0; i < N; ++i) {
      int w, v;
      scanf("%d %d", &w, &v);
      if (w >= 0 && v <= 0) {
	continue;
      } else if (w <= 0 && v >= 0) {
	W -= w;
	ans += v;
      } else {
	Goods g;
	g.w = w;
	g.v = v;
	if (g.w < 0 && g.v < 0) {
	  g.w = -g.w;
	  g.v = -g.v;
	  W += g.w;
	  ans -= g.v;
	}
	g.vdw = v / (w * 1.0);
	goods.push_back(g);
      }
    }
    sort(goods.begin(), goods.end(), GreaterVDW());

    for (unsigned int i = 0; i < goods.size(); ++i) {
      if (W < goods[i].w) {
	ans += (W / (goods[i].w * 1.0)) * goods[i].v;
	break;
      } else {
	ans += goods[i].v;
	W -= goods[i].w;
      }
    }
    printf("%.6f\n", ans);
  }
  return 0;
}