#include <bits/stdc++.h>
using namespace std;
string s, t;
int main() {
  int Gender = -1;
  bool correct = true;
  getline(cin, s);
  stringstream ss(s);
  int adj = 0, noun = 0, verb = 0;
  int counter = 0;
  while (ss >> t) {
    counter++;
    int n = t.size();
    if (n < 3) {
      correct = false;
      break;
    } else if (t.substr(n - 3, 3) == "etr") {
      if (Gender == 1) {
        correct = false;
        break;
      } else {
        Gender = 0;
        noun++;
        if (noun > 1 || verb > 0) {
          correct = false;
          break;
        }
      }
    } else if (n < 4) {
      correct = false;
      break;
    } else if (t.substr(n - 4, 4) == "lios") {
      if (Gender == 1) {
        correct = false;
        break;
      } else {
        Gender = 0;
        adj++;
        if (noun > 0 || verb > 0) {
          correct = false;
          break;
        }
      }
    } else if (t.substr(n - 4, 4) == "etra") {
      if (Gender == 0) {
        correct = false;
        break;
      } else {
        Gender = 1;
        noun++;
        if (noun > 1 || verb > 0) {
          correct = false;
          break;
        }
      }
    } else if (n < 5) {
      correct = false;
      break;
    } else if (t.substr(n - 5, 5) == "liala") {
      if (Gender == 0) {
        correct = false;
        break;
      } else {
        Gender = 1;
        adj++;
        if (noun > 0 || verb > 0) {
          correct = false;
          break;
        }
      }
    } else if (n < 6) {
      correct = false;
      break;
    } else if (t.substr(n - 6, 6) == "initis") {
      if (Gender == 1) {
        correct = false;
        break;
      } else {
        Gender = 0;
        verb++;
      }
    } else if (t.substr(n - 6, 6) == "inites") {
      if (Gender == 0) {
        correct = false;
        break;
      } else {
        Gender = 1;
        verb++;
      }
    } else {
      correct = false;
      break;
    }
  }
  if (counter > 1 && noun != 1) correct = false;
  if (correct)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
