#include <bits/stdc++.h>
using namespace std;
int main()
{
  int data[5];
  for(int i = 0;i < 5;i++)cin >> data[i];
  cout << *min_element(data,data + 3) + *min_element(data + 3,data + 5) - 50 << endl;
  return 0;
}
  