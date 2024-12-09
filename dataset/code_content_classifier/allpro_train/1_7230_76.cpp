#include <bits/stdc++.h>
using namespace std;
void minmax(int& a, int& b) {
  if (a > b) {
    swap(a, b);
  }
}
struct line {
  int x1;
  int y1;
  int x2;
  int y2;
  bool is_h() { return y1 == y2; }
  void normallize() {
    minmax(x1, x2);
    minmax(y1, y2);
  }
  void xy_swap() {
    swap(x1, y1);
    swap(x2, y2);
  }
};
void xy_swap(vector<line>& lines) {
  for (line& l : lines) l.xy_swap();
}
void hnormallize(vector<line>& lines) {
  sort(lines.begin(), lines.end(), [](line l1, line l2) {
    if (l1.y1 != l2.y1) return l1.y1 < l2.y1;
    return l1.x1 < l2.x1;
  });
  vector<line> cpy = vector<line>(lines.begin(), lines.end());
  lines.clear();
  for (line l : cpy) {
    if (lines.empty()) {
      lines.push_back(l);
    } else {
      if (l.y1 == lines.back().y1) {
        if (l.x1 <= lines.back().x2) {
          lines.back().x2 = max(l.x2, lines.back().x2);
        } else {
          lines.push_back(l);
        }
      } else {
        lines.push_back(l);
      }
    }
  }
}
long long count(vector<line>& lines) {
  long long result = 0;
  for (line l : lines) {
    result += ((long long)(l.x2 - l.x1) + (long long)(l.y2 - l.y1) + 1);
  }
  return result;
}
struct x2comp {
  bool operator()(line l1, line l2) { return l1.x2 < l2.x2; }
};
struct range_set {
  struct node {
    int x;
    int size;
    int height;
    node* left;
    node* right;
    node(int x) : x(x), size(1), height(1), left(nullptr), right(nullptr) {}
    void fix() {
      height = max((left ? left->height : 0), (right ? right->height : 0)) + 1;
      size = 1 + (left ? left->size : 0) + (right ? right->size : 0);
    }
    int factor() {
      return (left ? left->height : 0) - (right ? right->height : 0);
    }
    int query(int a, int b) {
      if (x >= b) return left ? left->query(a, b) : 0;
      if (x < a) return right ? right->query(a, b) : 0;
      return (left ? left->query_suffix(a) : 0) + 1 +
             (right ? right->query_prefix(b) : 0);
    }
    int query_prefix(int b) {
      if (x >= b) return left ? left->query_prefix(b) : 0;
      return (left ? left->size : 0) + 1 + (right ? right->query_prefix(b) : 0);
    }
    int query_suffix(int a) {
      if (x < a) return right ? right->query_suffix(a) : 0;
      return (left ? left->query_suffix(a) : 0) + 1 + (right ? right->size : 0);
    }
  };
  node* root;
  range_set() : root(nullptr) {}
  void insert(int x) { root = insert(root, x); }
  void erase(int x) { root = erase(root, x); }
  node* rotate_left(node* p) {
    node* q = p->right;
    p->right = q->left;
    q->left = p;
    p->fix();
    q->fix();
    return q;
  }
  node* rotate_right(node* p) {
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    p->fix();
    q->fix();
    return q;
  }
  node* balance(node* p) {
    p->fix();
    if (p->factor() == -2) {
      if (p->right->factor() > 0) p->right = rotate_right(p->right);
      return rotate_left(p);
    } else if (p->factor() == 2) {
      if (p->left->factor() < 0) p->left = rotate_left(p->left);
      return rotate_right(p);
    }
    return p;
  }
  node* insert(node* p, int x) {
    if (!p) return new node(x);
    if (x <= p->x)
      p->left = insert(p->left, x);
    else
      p->right = insert(p->right, x);
    return balance(p);
  }
  node* get_min(node* p) {
    if (!p) return nullptr;
    while (p->left) p = p->left;
    return p;
  }
  node* remove_min(node* p) {
    if (!p) return nullptr;
    if (p->left) {
      p->left = remove_min(p->left);
      return balance(p);
    }
    return p->right;
  }
  node* erase(node* p, int x) {
    if (!p) return nullptr;
    if (x < p->x) {
      p->left = erase(p->left, x);
    } else if (x > p->x) {
      p->right = erase(p->right, x);
    } else {
      node* q = p->left;
      node* r = p->right;
      delete p;
      if (!r) return q;
      node* min = get_min(r);
      min->right = remove_min(r);
      min->left = q;
      return balance(min);
    }
    return balance(p);
  }
  int count(int a, int b) { return root ? root->query(a, b) : 0; }
};
int main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<line> hlines = vector<line>();
  vector<line> vlines = vector<line>();
  for (int i = 0; i < n; i++) {
    line l;
    cin >> l.x1 >> l.y1 >> l.x2 >> l.y2;
    l.normallize();
    if (l.is_h())
      hlines.push_back(l);
    else
      vlines.push_back(l);
  }
  hnormallize(hlines);
  xy_swap(vlines);
  hnormallize(vlines);
  xy_swap(vlines);
  long long result = count(hlines) + count(vlines);
  if (!hlines.empty() && !vlines.empty()) {
    sort(hlines.begin(), hlines.end(),
         [](line l1, line l2) { return l1.x1 < l2.x1; });
    multiset<line, x2comp> pq = multiset<line, x2comp>();
    auto hItr = hlines.begin();
    range_set activeYs = range_set();
    for (line vl : vlines) {
      while (hItr != hlines.end() && hItr->x1 <= vl.x1) {
        activeYs.insert(hItr->y1);
        pq.insert(*hItr);
        ++hItr;
      }
      while (!pq.empty() && pq.begin()->x2 < vl.x1) {
        activeYs.erase(pq.begin()->y1);
        pq.erase(pq.begin());
      }
      result -= activeYs.count(vl.y1, vl.y2 + 1);
    }
  }
  cout << result << endl;
  return 0;
}
