#include <bits/stdc++.h>
using namespace std;
int main () {
  long N;
  cin >> N;
  long flag = 0, a, b, count = 1;
  cin >> b;
  for(int i = 1; i < N; i++){
    cin >> a;
    if(a == b)continue;
    else if(flag == 0){
      if(a > b)flag = -1;
      else flag = 1;
    } else if((flag == 1 && a > b) || (flag == -1 && a < b)){
      flag = 0;
      count++;
    }
    b = a;
  }
  cout << count << endl;
  return 0;
}