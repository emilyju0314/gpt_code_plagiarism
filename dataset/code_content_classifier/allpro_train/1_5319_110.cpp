#include <bits/stdc++.h>
using namespace std;
int check(vector<int> new_balls_array, int insert_position, int insert_value) {
  new_balls_array.insert(new_balls_array.begin() + insert_position,
                         insert_value);
  new_balls_array.push_back(101);
  int ans = 0;
  bool found = true;
  while (found) {
    found = false;
    int cnt = 0;
    int left = 0;
    int right = 0;
    for (int i = 0; i < new_balls_array.size(); i++) {
      if (new_balls_array[i] == new_balls_array[left]) {
        cnt++;
        right++;
      } else {
        if (cnt > 2) {
          found = true;
          vector<int> remaining_balls_array;
          for (int j = 0; j < left; j++) {
            remaining_balls_array.push_back(new_balls_array[j]);
          }
          for (int j = right; j < new_balls_array.size(); j++) {
            remaining_balls_array.push_back(new_balls_array[j]);
          }
          new_balls_array.swap(remaining_balls_array);
          ans += right - left;
          break;
        } else {
          cnt = 1;
          left = i;
          right = i + 1;
        }
      }
    }
  }
  return ans - 1;
}
int main() {
  int n, k, x;
  int ans = 0;
  cin >> n >> k >> x;
  vector<int> balls_array(n);
  for (int i = 0; i < n; i++) cin >> balls_array[i];
  vector<int> new_balls_array = balls_array;
  for (int i = 0; i < n; i++) {
    ans = max(ans, check(new_balls_array, i, x));
  }
  cout << ans;
  return 0;
}
