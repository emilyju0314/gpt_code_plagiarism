#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int n;
  cin>>n;
  int a[100000];
  int ct=0;
  int s=0;
  for(int i=0; i<n; i++){
    cin>>a[i];
    if(a[i]&1) ct++;
    s^=a[i];
  }
  if(s==1){
    cout<<"Bob"<<endl;
  }else if(s>1){
    cout<<"Alice"<<endl;
  }else if(ct>0){
    cout<<"Alice"<<endl;
  }else{
    cout<<"Bob"<<endl;
  }
	return 0;
}
