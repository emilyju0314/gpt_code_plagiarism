// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2369

#include <iostream>
#include <string>
using namespace std;

string A[4] = { "mew", "mXew", "meXw", "mXeXw" };

int main() {
  string S;
  cin >> S;
  if (S == "") S = "X";
  for (int s = S.size(); true; s = S.size()) {
    int i;
    for (int j=0; j<4; j++) {
      if ((i = S.find(A[j])) != -1) {
	S.replace(i, A[j].size(), "X");
      }
    }
    if (s == S.size()) break;
  }
  if (S == "X") {
    cout << "Cat" << endl;
  } else {
    cout << "Rabbit" << endl;
  }
}