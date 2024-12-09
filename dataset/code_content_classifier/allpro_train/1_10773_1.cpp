#include <bits/stdc++.h>
using namespace std;
int n, m;
set<int> ms;
int main() {
  ifstream myReadFile;
  myReadFile.open("input.txt");
  ofstream myfile;
  myfile.open("output.txt");
  int n;
  myReadFile >> n;
  cin >> n;
  char str[200];
  myReadFile >> str;
  cin >> str;
  int i = 0;
  while (str[i] != '1' && i < n) i++;
  for (int j = i + 1; j < n; j++) {
    if (str[j] == '1') {
      ms.insert(j - i);
      i = j;
    }
  }
  if (ms.size() == 1) {
    myfile << "YES";
    cout << "YES";
  } else {
    myfile << "NO";
    cout << "NO";
  }
  myReadFile.close();
  myfile.close();
  return 0;
}
