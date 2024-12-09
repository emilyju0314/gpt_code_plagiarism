#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool flg;

void rec(vector<int> c,int sum,vector<int> &vv){
  if(sum == 0){
    flg = true;
    return;
  }

  for(int i = 1 ; i <= 13 ; i++){     

    if(c[i] && sum % i == 0){
      int m = i;
      vv.push_back(i);
      c[i]--;
      rec(c,sum-m,vv);
      if(flg) return;
      vv.pop_back();
      c[i]++;
    }

  }
}

int main(){
  while(cin >> n ,n){
    int sum = 0,a;
    vector<int> c(14,0);

    for(int i = 0 ; i < n ; i++){
      cin >> a;
      sum += a;
      c[a]++;
    }

    flg = false;    
    vector<int> v;
    rec(c,sum,v);
    

    if(v.size()){
      int s = (int)v.size();
      for(int i = 0 ; i < s ; i++){
	if(!i) cout << v[s-1-i];
	else cout << " " << v[s-1-i];
      }
      cout << endl;
    }
    else{
      cout << "No" << endl;
    }
  }

  return 0;
}