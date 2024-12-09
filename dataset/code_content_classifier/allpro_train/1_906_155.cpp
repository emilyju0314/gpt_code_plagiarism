#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(0);
  int n = 0;
  while (cin >> n) {
    vector<unsigned int> positive_cost;
    vector<int> negative_cost;
    vector<int> zero;
    bool good_mood = false;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      temp > 0
          ? positive_cost.push_back(temp)
          : (temp < 0 ? negative_cost.push_back(temp) : zero.push_back(temp));
    }
    sort(positive_cost.begin(), positive_cost.end());
    sort(negative_cost.begin(), negative_cost.end());
    if (negative_cost.size() % 2 == 1)
      good_mood = false;
    else
      good_mood = true;
    if (good_mood) {
      for (int i = 0; i < negative_cost.size(); i++) {
        cout << negative_cost[i] << " ";
      }
      for (int i = 0; i < positive_cost.size(); i++) {
        cout << positive_cost[i] << " ";
      }
      if (negative_cost.size() == 0 && positive_cost.size() == 0)
        cout << zero[0];
    } else {
      if (positive_cost.size() == 0) {
        if (negative_cost.size() > 1) {
          for (int i = 0; i < negative_cost.size() - 1; i++) {
            cout << negative_cost[i] << " ";
          }
        } else {
          if (zero.size() == 0) {
            cout << negative_cost[0];
          } else {
            cout << zero[0];
          }
        }
      } else {
        for (int i = 0; i < negative_cost.size() - 1; i++) {
          cout << negative_cost[i] << " ";
        }
        for (int i = 0; i < positive_cost.size(); i++) {
          cout << positive_cost[i] << " ";
        }
      }
    }
    cout << endl;
  }
  return 0;
}
