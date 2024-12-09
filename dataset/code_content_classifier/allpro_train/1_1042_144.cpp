#include <bits/stdc++.h>
using namespace std;

int a[100001];

int partition(int p, int r){
  int x = a[r];
  int idx = p-1;
  for(int i = p; i < r; i++){
    if(a[i] <= x){
      idx++;
      swap(a[idx], a[i]);
    }
  }
  swap(a[idx+1], a[r]);
  return idx+1;
}

int main(){

  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  int q = partition(0, n-1);
  for(int i = 0; i < n; i++){
    if(i) cout << " ";
    if(i == q) cout << "[";
    cout << a[i];
    if(i == q) cout << "]";
  }
  cout << "\n";
  return 0;
}
