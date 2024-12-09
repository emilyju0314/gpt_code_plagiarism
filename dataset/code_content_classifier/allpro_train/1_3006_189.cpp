#include <iostream>
using namespace std;
 
int main() {
 int x, y;
 cin >> x >> y;
 if (y == 1)
   cout << "0";
 else
   cout << x - y;
}