#include <iostream>
#include <bitset>

using namespace std;

int main(){
  unsigned int n;

  cin >> n;

  bitset<32> b(n),b1,b2;

  b1 = b << 1;
  b2 = b >> 1;

  cout << b << endl;
  cout << b.flip() << endl;
  cout << b1 << endl;
  cout << b2 << endl;

  return 0;
}

