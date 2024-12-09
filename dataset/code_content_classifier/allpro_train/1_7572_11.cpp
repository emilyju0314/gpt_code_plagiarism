#include <bits/stdc++.h>
using namespace std;
vector<int> sum1;
vector<int> sum2;
bool f(const pair<int, int> &a, const pair<int, int> b) {
  return a.first < b.first;
}
int main() {
  int n;
  vector<int> result;
  vector<pair<int, int> > answers;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    result.push_back(a);
    if (i == 0) {
      if (a == 1) {
        sum1.push_back(1);
        sum2.push_back(0);
      } else {
        sum1.push_back(0);
        sum2.push_back(1);
      }
    } else {
      if (a == 1) {
        sum1.push_back(sum1[i - 1] + 1);
        sum2.push_back(sum2[i - 1]);
      } else {
        sum1.push_back(sum1[i - 1]);
        sum2.push_back(sum2[i - 1] + 1);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int firstSets = 0;
    int secondsSets = 0;
    int last_pos = -1;
    bool correct = true;
    bool first_player_last = false;
    while (last_pos != n - 1) {
      int begin = last_pos + 1;
      int end = min(last_pos + 2 * i + 1, n - 1);
      while (end - begin > 1) {
        int current = (begin + end) / 2;
        int firstRounds = sum1[current] - (last_pos == -1 ? 0 : sum1[last_pos]);
        int secondRounds =
            sum2[current] - (last_pos == -1 ? 0 : sum2[last_pos]);
        if (firstRounds >= i || secondRounds >= i) {
          end = current;
        } else {
          begin = current;
        }
      }
      int firstRounds = sum1[begin] - (last_pos == -1 ? 0 : sum1[last_pos]);
      int secondRounds = sum2[begin] - (last_pos == -1 ? 0 : sum2[last_pos]);
      if (firstRounds != i && secondRounds != i) {
        firstRounds = sum1[end] - (last_pos == -1 ? 0 : sum1[last_pos]);
        secondRounds = sum2[end] - (last_pos == -1 ? 0 : sum2[last_pos]);
        if (firstRounds != i && secondRounds != i) {
          correct = false;
          break;
        }
        if (firstRounds == i) {
          firstSets++;
          if (end == n - 1) first_player_last = true;
        } else
          secondsSets++;
        last_pos = end;
      } else {
        if (firstRounds == i) {
          firstSets++;
          if (begin == n - 1) first_player_last = true;
        } else
          secondsSets++;
        last_pos = begin;
      }
    }
    if (correct && ((firstSets > secondsSets && first_player_last) ||
                    (secondsSets > firstSets && !first_player_last))) {
      answers.push_back(make_pair(max(firstSets, secondsSets), i));
    }
  }
  sort(answers.begin(), answers.end(), f);
  cout << answers.size() << endl;
  for (int i = 0; i < answers.size(); i++) {
    cout << answers[i].first << " " << answers[i].second << endl;
  }
  return 0;
}
