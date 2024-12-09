#include <iostream>
#include <cstdio>

using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=1;i<=n;i++) cin >> a[i];
  for(int i=1;i<=n;i++){
    printf("node %d: key = %d, ",i,a[i]);
    if(i/2!=0) printf("parent key = %d, ",a[i/2]);
    if(2*i<=n) printf("left key = %d, ",a[2*i]);
    if(2*i+1<=n) printf("right key = %d, ",a[2*i+1]);
    cout << endl;
  }
}