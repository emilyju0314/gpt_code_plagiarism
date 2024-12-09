#include<iostream>
using namespace std;
int main(){
  int n;
  int array[200005];
  cin>>n;
  
  int bit=0;
  for(int i=0;i<n;i++){
    cin>>array[i];
    bit^=array[i];
  }
  
  for(int i=0;i<n;i++){
    cout << (bit^array[i]) << endl;
  }
  return(0);
}