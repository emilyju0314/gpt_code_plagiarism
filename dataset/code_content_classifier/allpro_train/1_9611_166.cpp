#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
  int n;
  while( cin >> n,n ){
    int ansm = 1000000000;
    int ansM = 0;
    for(int i = 0 ; i < n ; i++){
      int sum = 0;
      for(int j = 0 ; j < 5 ; j++){
	int a;
	cin >> a;
	sum+=a;
      }
      if(ansm > sum)ansm = sum;
      if(ansM < sum)ansM = sum;
    }
    cout << ansM << ' ' << ansm << endl;
  }
  return 0;
}