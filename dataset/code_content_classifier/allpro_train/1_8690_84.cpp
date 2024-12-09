#include <bits/stdc++.h>
using namespace std;
struct order {
  long long hairs;
  long long annoyance;
  size_t index;
  order(long long hairs, long long annoyance, size_t index)
      : hairs(hairs), annoyance(annoyance), index(index) {}
  order() : hairs(-1), annoyance(-1), index(999999) {}
};
bool compare1(const order& l, const order& r) {
  return (l.annoyance == r.annoyance) ? l.hairs > r.hairs
                                      : l.annoyance < r.annoyance;
}
bool compare2(const order& l, const order& r) {
  return (l.hairs == r.hairs) ? l.annoyance > r.annoyance : l.hairs > r.hairs;
}
bool compare3(const order& l, const order& r) {
  return (l.annoyance == r.annoyance) ? l.hairs > r.hairs
                                      : l.annoyance < r.annoyance;
}
void printNode(order n) { cout << n.index + 1 << " "; }
int main() {
  ios_base::sync_with_stdio(false);
  size_t n;
  cin >> n;
  size_t p;
  cin >> p;
  size_t k;
  cin >> k;
  vector<order> nodes(n);
  for (size_t i = 0; i < n; i++) {
    long long hairs;
    cin >> hairs;
    long long annoyance;
    cin >> annoyance;
    nodes[i] = order(hairs, annoyance, i);
  }
  size_t nonExeuctedOrderCount = p - k;
  sort(nodes.begin(), nodes.end(), compare1);
  sort(nodes.begin() + nonExeuctedOrderCount, nodes.end(), compare2);
  sort(nodes.begin() + p, nodes.end(), compare3);
  long long minimumAnnoynace = numeric_limits<long long>::max();
  for (size_t i = nonExeuctedOrderCount; i < nonExeuctedOrderCount + k; i++) {
    minimumAnnoynace = min(minimumAnnoynace, nodes[i].annoyance);
    printNode(nodes[i]);
  }
  long long lastFitIndex = 0;
  for (size_t i = p; i < n; i++) {
    if (nodes[i].annoyance >= minimumAnnoynace) break;
    lastFitIndex++;
  }
  long long printedNonExecutedOrderCount = 0;
  for (size_t i = p + lastFitIndex - 1; i >= p; i--) {
    printedNonExecutedOrderCount++;
    if (printedNonExecutedOrderCount > nonExeuctedOrderCount) break;
    printNode(nodes[i]);
  }
  for (size_t i = printedNonExecutedOrderCount; i < nonExeuctedOrderCount; i++)
    printNode(nodes[i]);
  return 0;
}
