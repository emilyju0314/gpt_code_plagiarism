#include<iostream>
using namespace std;

int main(){
  int n,k,a[100000],sum,maxv;
  
  while(cin >> n >> k,n||k){
    sum = 0;
    for(int i=0;i<k;i++){
      cin >> a[i]; sum += a[i];
    }
    
    maxv = sum;
    for(int i=k;i<n;i++){
      cin >> a[i]; sum += a[i] - a[i-k];
      maxv = std::max(maxv,sum);
    }
    cout << maxv << endl;
  }
}
		   