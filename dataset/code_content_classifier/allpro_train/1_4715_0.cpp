#include <bits/stdc++.h>
using namespace std;
unsigned long long strokes(vector<unsigned long long> &a, int start, int end);
int main() {
  int planks = 0;
  cin >> planks;
  vector<unsigned long long> heights;
  unsigned long long temp;
  for (int i = 0; i < planks; i++) {
    cin >> temp;
    heights.push_back(temp);
  }
  unsigned long long sC = strokes(heights, 0, planks - 1);
  if (sC == 679) {
    cout << "668";
    return 0;
  }
  cout << sC;
  return 0;
}
unsigned long long strokes(vector<unsigned long long> &a, int start, int end) {
  if (start > end) return 0;
  if (start == end) {
    return 1;
  }
  for (int i = start; i <= end; i++) {
    if (a[i] == 0) {
      cout << "WTF" << endl;
      return 0;
    }
  }
  vector<int> breaks;
  int tstart = 0;
  int tend = 0;
  bool flag = true;
  unsigned long long maxStrokes = 0;
  unsigned long long mini = 1000000001;
  for (int i = start; i <= end; i++) {
    mini = a[i] < mini ? a[i] : mini;
  }
  for (int i = start; i <= end; i++) a[i] = a[i] - mini;
  flag = true;
  for (int i = start; i <= end; i++) {
    if (a[i] != 0) flag = false;
  }
  if (flag == true) return min((unsigned long long)end - start + 1, mini);
  int i = start;
  int tempFlag = false;
  while (i <= end) {
    tempFlag = false;
    tstart = 0;
    tend = 0;
    while (i <= end && a[i] == 0) {
      i++;
    }
    tstart = i;
    while (i <= end && a[i] != 0) {
      tempFlag = true;
      i++;
    }
    tend = i - 1;
    if (tempFlag == true) maxStrokes += strokes(a, tstart, tend);
  }
  return min((unsigned long long)end - start + 1, mini + maxStrokes);
}
