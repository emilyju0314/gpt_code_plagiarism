#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
  int n;
  cin >> n;
  unsigned int a[100001]={};
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  sort(a, a+n);
  reverse(a, a+n);
  long long int x[2]={};
  int k=0;
  for(int i=1; i<n; i++){
    if(a[i-1]==a[i]){
      x[k]=a[i];
      if(x[1]!=0){
        break;
      }
      k++;
      i++;
    }
  }
  cout << x[0]*x[1] << endl;
  return 0;


}
