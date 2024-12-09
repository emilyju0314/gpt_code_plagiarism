#include <bits/stdc++.h>
using namespace std;
class Homework {
 public:
  void MinimumRemainingChars() {
    std::string input;
    cin >> input;
    int k;
    cin >> k;
    std::unordered_map<char, int> charCount;
    for (size_t i = 0; i < input.length(); i++) {
      auto it = charCount.find(input[i]);
      if (it == charCount.end()) {
        charCount.insert(std::make_pair(input[i], 1));
      } else {
        it->second++;
      }
    }
    priority_queue<std::pair<char, int>, vector<std::pair<char, int> >,
                   CharCountComparator>
        charCountQueue(charCount.begin(), charCount.end());
    std::unordered_set<char> charsToRemove;
    while (k > 0 && !charCountQueue.empty() &&
           charCountQueue.top().second <= k) {
      const std::pair<char, int>& charWithCount = charCountQueue.top();
      k -= charWithCount.second;
      charsToRemove.insert(charWithCount.first);
      charCountQueue.pop();
    }
    cout << charCountQueue.size();
    std::string inputWithRemovedChars;
    for (size_t i = 0; i < input.length(); i++) {
      if (charsToRemove.count(input[i]) != 1) {
        inputWithRemovedChars.push_back(input[i]);
      }
    }
    cout << '\n' << inputWithRemovedChars;
  }

 private:
  struct CharCountComparator {
    bool operator()(const std::pair<char, int>& lhs,
                    const std::pair<char, int>& rhs) const {
      return lhs.second > rhs.second;
    }
  };
};
int main() {
  Homework s;
  s.MinimumRemainingChars();
  return 0;
}
