#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <unordered_map>
#include <tuple>

using namespace std;

struct Rect {
  int x;
  int y;
  int width;
  int height;
  int cross_x;
  int cross_y;
};

template<typename T>
struct RPN {
  deque<T> data;
  T& operator[](int i) {
    return data[data.size() - i - 1];
  }
  void push(T x) {
    data.push_back(x);
  }
  void pop(int n) {
    for (int i = 0; i < n; ++i) {
      data.pop_back();
    }
  }
  int size() {
    return data.size();
  }
};

bool get_tile(vector<char>& A, int N, int x, int y, int& width, int& height) {
  if (x % 2 != 0 || y % 2 != 0) {
    return false;
  }
  int w = N - x;
  int h = N - y;
  for (int i = x; i < N; ++i) {
    if (A[i + N * y] == 'x') {
      w = i - x;
      break;
    }
  }
  for (int i = y; i < N; ++i) {
    if (A[x + N * i] == 'x') {
      h = i - y;
      break;
    }
  }
  if (y + h < N) {
    for (int i = x; i < x + w; ++i) {
      if (A[i + N * (y + h)] == 'o') {
        return false;
      }
    }
  }
  if (x + w < N) {
    for (int i = y; i < y + h; ++i) {
      if (A[x + w + N * i] == 'o') {
        return false;
      }
    }
  }
  if (y + h < N && x + w < N) {
    if (A[x + w + N * (y + h)] == 'o') {
      return false;
    }
  }
  for (int i = x + 1; i < x + w; ++i) {
    for (int j = y + 1; j < y + h; ++j) {
      if (A[i + N * j] == 'x') {
        return false;
      }
    }
  }
  width = w;
  height = h;
  return true;
}

int main() {
  int N;
  cin >> N;
  vector<char> A(N * N);
  unordered_map<int, pair<int, int>> rects;
  queue<tuple<int, int, int, int>> q;
  for (int j = 0; j < N; ++j) {
    for (int i = 0; i < N; ++i) {
      cin >> A[i + N * j];
    }
  }
  int width;
  int height;
  if (!get_tile(A, N, 0, 0, width, height)) {
    cout << -1 << endl;
    return 0;
  }
  q.emplace(0, 0, width, height);
  rects.emplace(0, make_pair(width, height));
  while (!q.empty()) {
    tuple<int, int, int, int> rect = q.front();
    int x = get<0>(rect);
    int y = get<1>(rect);
    int w = get<2>(rect);
    int h = get<3>(rect);
    q.pop();
    if (w != 0 && h != 0) {
//       cout << x << ", " << y << ", " << w << ", " << h << endl;
    }
    rects.emplace(x + 10000 * y, make_pair(w, h));
    if (x + w < N && rects.find((x + w + 1) + 10000 * y) == rects.end()) {
      if (!get_tile(A, N, x + w + 1, y, width, height)) {
        cout << -1 << endl;
        return 0;
      }
      q.emplace(x + w + 1, y, width, height);
      rects.emplace((x + w + 1) + 10000 * y, make_pair(width, height));
    }
    if (y + h < N && rects.find(x + 10000 * (y + h + 1)) == rects.end()) {
      if (!get_tile(A, N, x, y + h + 1, width, height)) {
        cout << -1 << endl;
        return 0;
      }
      q.emplace(x, y + h + 1, width, height);
      rects.emplace(x + 10000 * (y + h + 1), make_pair(width, height));
    }
  }
  unordered_map<int, vector<int>> tree;
  RPN<pair<Rect, int>> rpn;
  if (rects[0].first == N && rects[0].second == N) {
    cout << 0 << endl;
    return 0;
  }
  rpn.push(make_pair(Rect {0, 0, rects[0].first, rects[0].second, -1, -1}, 0));
  int merge_count = 0;
  while (true) {
    int type = rpn[0].second;
    if (type == 3) {
      if (rpn[0].first.width != rpn[3].first.width ||
          rpn[1].first.width != rpn[2].first.width ||
          rpn[2].first.height != rpn[3].first.height ||
          rpn[0].first.height != rpn[1].first.height) {
        cout << -1 << endl;
        return 0;
      }
      int new_x = rpn[3].first.x;
      int new_y = rpn[3].first.y;
      int new_w = rpn[3].first.width + rpn[2].first.width + 1;
      int new_h = rpn[3].first.height + rpn[0].first.height + 1;
      int cross_x = rpn[1].first.x - 1;
      int cross_y = rpn[1].first.y - 1;
      vector<int> children;
      if (rpn[0].first.cross_x != -1) {
        children.emplace_back(rpn[0].first.cross_x + 10000 * rpn[0].first.cross_y);
      }
      if (rpn[1].first.cross_x != -1) {
        children.emplace_back(rpn[1].first.cross_x + 10000 * rpn[1].first.cross_y);
      }
      if (rpn[2].first.cross_x != -1) {
        children.emplace_back(rpn[2].first.cross_x + 10000 * rpn[2].first.cross_y);
      }
      if (rpn[3].first.cross_x != -1) {
        children.emplace_back(rpn[3].first.cross_x + 10000 * rpn[3].first.cross_y);
      }
      tree.emplace((rpn[1].first.x - 1) + 10000 * (rpn[1].first.y - 1), children);
      rpn.pop(4);
      rpn.push(make_pair(Rect {new_x, new_y, new_w, new_h, cross_x, cross_y}, -1));
      ++merge_count;
//       cout << "merge: (" << new_x << ", " << new_y << ", " << new_w << ", " << new_h << ")" << endl;
    } else if (type == 2) {
      int x = rpn[2].first.x;
      int y = rpn[2].first.y + rpn[2].first.height + 1;
      if (y >= N) {
        cout << -1 << endl;
        return 0;
      }
      int w = rects[x + 10000 * y].first;
      int h = rects[x + 10000 * y].second;
      rpn.push(make_pair(Rect {x, y, w, h, -1, -1}, -1));
//       cout << "add: (" << x << ", " << y << ", " << w << ", " << h << ")" << endl;
    } else if (type == 1) {
      int x = rpn[0].first.x;
      int y = rpn[0].first.y + rpn[0].first.height + 1;
      if (y >= N) {
        cout << -1 << endl;
        return 0;
      }
      int w = rects[x + 10000 * y].first;
      int h = rects[x + 10000 * y].second;
      rpn.push(make_pair(Rect {x, y, w, h, -1, -1}, -1));
//       cout << "add: (" << x << ", " << y << ", " << w << ", " << h << ")" << endl;
    } else if (type == 0) {
      int x = rpn[0].first.x + rpn[0].first.width + 1;
      if (x >= N) {
        cout << -1 << endl;
        return 0;
      }
      int y = rpn[0].first.y;
      int w = rects[x + 10000 * y].first;
      int h = rects[x + 10000 * y].second;
      rpn.push(make_pair(Rect {x, y, w, h, -1, -1}, -1));
//       cout << "add: (" << x << ", " << y << ", " << w << ", " << h << ")" << endl;
    } else {
      if (rpn.size() == 1) {
        if (rpn[0].first.width == N && rpn[0].first.height == N) {
          break;
        } else {
          rpn[0].second = 0;
        }
      } else {
        int prevtype = rpn[1].second;
        if (prevtype == 2) {
          if (rpn[0].first.height < rpn[1].first.height) {
            rpn[0].second = 0;
          } else {
            rpn[0].second = 3;
          }
        } else if (prevtype == 1) {
          if (rpn[0].first.width < rpn[1].first.width) {
            rpn[0].second = 0;
          } else {
            rpn[0].second = 2;
          }
        } else if (prevtype == 0) {
          if (rpn[0].first.height < rpn[1].first.height) {
            rpn[0].second = 0;
          } else {
            rpn[0].second = 1;
          }
        }
      }
    }
  }
  priority_queue<int, vector<int>, std::greater<int>> pq;
  pq.push(rpn[0].first.cross_x + 10000 * rpn[0].first.cross_y);
  cout << merge_count << endl;
  while (!pq.empty()) {
    int cross = pq.top();
    pq.pop();
    for (int child_cross : tree[cross]) {
      pq.push(child_cross);
    }
    cout << (cross / 10000 + 1) << endl;
    cout << (cross % 10000 + 1) << endl;
  }
}
