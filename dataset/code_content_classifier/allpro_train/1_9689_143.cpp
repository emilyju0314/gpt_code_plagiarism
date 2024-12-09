#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string S;
int cur = 0;

int digit() {
  return S[cur++] - '0';
}

int number() {
  int n = digit();
  while(cur < S.size() && isdigit(S[cur])) n = n * 10 + digit();
  return n;
}

int expression();

int factor() {
  if(S[cur] != '(') return number();
  cur++;
  int n = expression();
  cur++;
  return n;
}

int term() {
  int n = factor();
  while(cur < S.size() && (S[cur] == '*' || S[cur] == '/')) {
    char op = S[cur++];
    if(op == '*') n *= factor(); else n /= factor();
  }
  return n;
}

int expression() {
  int n = term();
  while(cur < S.size() && (S[cur] == '+' || S[cur] == '-')) {
    char op = S[cur++];
    if(op == '+') n += term(); else n -= term();
  }
  return n;
}

int main() {
  int n;
  cin >> n;
  for(int i = 0;i < n;i++) {
    cur = 0;
    cin >> S;
    S.erase(S.size() - 1);
    cout << expression() << endl;
  }
}