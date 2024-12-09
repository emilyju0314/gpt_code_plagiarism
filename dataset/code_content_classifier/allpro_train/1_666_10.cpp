#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N; cin >> N;
  
  vector<int> v;
  for (int i=0; i<N; i++) 
  {
      int a; cin >> a;
      v.push_back(a);
  }

  int xorNum = 0;
  for (int i=0; i<N; i++) {
    xorNum ^= v.at(i);
  }
  
  cout << ((xorNum == 0) ? "Yes" : "No") << endl;
}