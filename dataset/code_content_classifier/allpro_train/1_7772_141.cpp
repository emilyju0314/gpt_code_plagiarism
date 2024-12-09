#include<bits/stdc++.h>
using namespace std;

int main() {
  long long K, A, B, sum;
  cin >> K >> A >> B;
  long long num = K-(A+1);
  if(B-A >= 3 && K -A >= 1) {
  sum = (num / 2) * (B - A) +  (num % 2) + B;
    cout << sum;
  }else{
    cout << K+1;
  }
}
