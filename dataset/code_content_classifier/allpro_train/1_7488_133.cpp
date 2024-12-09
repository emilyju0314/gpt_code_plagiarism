#include <bits/stdc++.h>
struct WorklistEntry {
  int height;
  int count;
  WorklistEntry(int height, int count) : height(height), count(count) {}
};
void runTest();
std::vector<int> parseInput();
long long computeResult(std::vector<int>& heights);
long long wrapAroundPairs(const std::vector<int>& heights);
int argmax(const std::vector<int>& array);
void printOutput(long long numVisiblePairs);
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  runTest();
  return 0;
}
void runTest() {
  std::vector<int> heights = parseInput();
  long long numVisiblePairs = computeResult(heights);
  printOutput(numVisiblePairs);
}
std::vector<int> parseInput() {
  int numHills;
  std::cin >> numHills;
  std::vector<int> heights;
  for (int i = 0; i < numHills; i++) {
    int height;
    std::cin >> height;
    heights.push_back(height);
  }
  return heights;
}
long long computeResult(std::vector<int>& heights) {
  int startIndex = argmax(heights);
  std::rotate(heights.begin(), heights.begin() + startIndex, heights.end());
  long long result = 0;
  std::stack<WorklistEntry> worklist;
  for (int height : heights) {
    int count = 1;
    while (!worklist.empty() && height >= worklist.top().height) {
      result += worklist.top().count;
      if (height == worklist.top().height) {
        count += worklist.top().count;
      }
      worklist.pop();
    }
    if (!worklist.empty()) {
      result += 1;
    }
    worklist.push({height, count});
  }
  result += wrapAroundPairs(heights);
  return result;
}
long long wrapAroundPairs(const std::vector<int>& heights) {
  int n = heights.size();
  std::vector<bool> visibleFromFront(n);
  int maxHeight = INT_MIN;
  for (int index = 1; index < n; index++) {
    visibleFromFront[index] =
        maxHeight <= heights[0] && maxHeight <= heights[index];
    maxHeight = std::max(maxHeight, heights[index]);
  }
  std::vector<bool> visibleFromBack(n);
  maxHeight = INT_MIN;
  for (int index = n - 1; index > 0; index--) {
    visibleFromBack[index] =
        maxHeight <= heights[0] && maxHeight <= heights[index];
    maxHeight = std::max(maxHeight, heights[index]);
  }
  long long result = 0;
  for (int index = 1; index < n; index++) {
    if (!visibleFromFront[index] && visibleFromBack[index]) {
      result++;
    }
  }
  return result;
}
int argmax(const std::vector<int>& array) {
  int result = 0;
  for (int index = 1; index < array.size(); index++) {
    if (array[index] > array[result]) {
      result = index;
    }
  }
  return result;
}
void printOutput(long long numVisiblePairs) {
  std::cout << numVisiblePairs << std::endl;
}
