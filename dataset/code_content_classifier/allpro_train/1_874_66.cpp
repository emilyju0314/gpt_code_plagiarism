#include <bits/stdc++.h>
int n, k;
long long res = 0;
int min(int a, int b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a < b ? b : a; }
class Song {
 public:
  int t_;
  int b_;
} songs[300001];
class MinHeap {
 public:
  void push(int value) {
    if (size_ < k) {
      sum_ += value;
      int child = size_++;
      while (child != 0) {
        int parent = (child - 1) / 2;
        if (data_[parent] < value) break;
        data_[child] = data_[parent];
        child = parent;
      }
      data_[child] = value;
      return;
    }
    if (data_[0] > value) return;
    sum_ += value - data_[0];
    int parent = 0;
    int child = 1;
    while (child < size_) {
      if (child + 1 < size_ && data_[child + 1] < data_[child]) ++child;
      if (data_[child] >= value) break;
      data_[parent] = data_[child];
      parent = child;
      child = 2 * parent + 1;
    }
    data_[parent] = value;
  }
  long long sum_ = 0;

 private:
  int data_[300001];
  int size_ = 0;
} heap;
int main(int argc, char** argv) {
  scanf("%d %d", &n, &k);
  for (register int i = 0; i < n; ++i)
    scanf("%d %d", &songs[i].t_, &songs[i].b_);
  std::sort(songs, songs + n,
            [](const Song& a, const Song& b) { return a.b_ > b.b_; });
  for (register int i = 0; i < n; ++i) {
    heap.push(songs[i].t_);
    res = max(res, heap.sum_ * songs[i].b_);
  }
  printf("%lld", res);
  return 0;
}
