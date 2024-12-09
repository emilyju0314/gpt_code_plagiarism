#include <bits/stdc++.h>
using namespace std;
using namespace std;
int inquire(int x, int y) {
  cout << "? " << x + 1 << " " << y + 1 << endl;
  int a;
  cin >> a;
  return a;
}
const long long int INF = 0x3f3f3f3f;
const long long int bignum = 1e18;
int n;
vector<int> lists;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  lists.resize(n);
  int neg = 0;
  vector<int> less;
  vector<int> great;
  vector<int> equal;
  for (int i = 0; i < n; i++) {
    cin >> lists[i];
    if (lists[i] < 0) neg++;
  }
  if (neg < 3) {
    bool done = false;
    for (int i = 0; i < n; i++) {
      if (lists[i] < 0 && !done) {
        less.push_back(lists[i]);
        done = true;
      } else if (lists[i] < 0) {
        equal.push_back(lists[i]);
      } else if (lists[i] == 0)
        equal.push_back(lists[i]);
      else
        great.push_back(lists[i]);
    }
  } else {
    bool done = false;
    int count = 2;
    for (int i = 0; i < n; i++) {
      if (lists[i] < 0 && !done) {
        less.push_back(lists[i]);
        done = true;
      } else if (lists[i] < 0 && count > 0) {
        great.push_back(lists[i]);
        count--;
      } else if (lists[i] <= 0)
        equal.push_back(lists[i]);
      else
        great.push_back(lists[i]);
    }
  }
  cout << less.size() << " ";
  {
    for (int i = 0; i < less.size(); i++) cout << less[i] << " ";
    cout << "\n";
  };
  cout << great.size() << " ";
  {
    for (int i = 0; i < great.size(); i++) cout << great[i] << " ";
    cout << "\n";
  };
  cout << equal.size() << " ";
  {
    for (int i = 0; i < equal.size(); i++) cout << equal[i] << " ";
    cout << "\n";
  };
  return 0;
}
