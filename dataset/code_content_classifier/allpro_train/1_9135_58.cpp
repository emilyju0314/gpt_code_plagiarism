#include <bits/stdc++.h>
using namespace std;
int main() {
  string spider, spider1 = "";
  int i, j, k, bigger = 0, smaller = 0;
  cin >> spider;
  for (i = 0; i < spider.size(); i++) {
    if (spider[i] >= 'A' && spider[i] <= 'Z')
      bigger++;
    else
      smaller++;
  }
  if (smaller > bigger) {
    for (i = 0; i < spider.size(); i++) {
      spider[i] = tolower(spider[i]);
    }
    cout << spider << endl;
  } else if (bigger > smaller) {
    for (int i = 0; i < spider.size(); i++) {
      spider[i] = toupper(spider[i]);
    }
    cout << spider << endl;
  } else if (smaller == bigger) {
    for (int i = 0; i < spider.size(); i++) {
      spider[i] = tolower(spider[i]);
    }
    cout << spider << endl;
  }
  return 0;
}
