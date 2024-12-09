#include <iostream>

using namespace std;

int main(){
  while (true) {
    int n;
    cin>>n;

    if (n == 0)
      break;

    int left = 1;
    int right = 1;
    long long sum = 0;

    while (true) {
      if (sum < n) {
	sum += right++;
      } else if (sum > n) {
	sum -= left;
	left++;
      } else {
	break;
     }
    }
    cout<<left<<" "<<(right - left)<<endl;
  }
}

