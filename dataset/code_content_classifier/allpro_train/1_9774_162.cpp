#include <iostream>
using namespace std;
int main() {
 char str[20];
 cin >> str;
 str[5] = str[13] = ' ';
 cout << str << endl;
 return 0;
}