#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<stack>
#include<map>
#include<set>
#include<string>
#include <sstream>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

using namespace std;

int lower_bound_sub(vector<int>* a,int k,int min,int max){
  if(min > max){
    return a->size();
  }
  else{
    int mid = min + (max - min) / 2;
    if(a->at(mid) >= k && mid == 0){
      return mid;
    }
    else if(a->at(mid) >= k && a->at(mid-1) < k){
      return mid;
    }
    else if(a->at(mid) >= k){
      return lower_bound_sub(a,k,min,mid-1);
    }
    else {
      return lower_bound_sub(a,k,mid+1,max);
    }

  }

}

int lower_bound(vector<int>* a,int k){
  return lower_bound_sub(a,k,0,a->size()-1);
}

int main(){
  long ii,jj,kk,n,q;
  int k;
  vector<int> a;

  cin >> n;

  a.resize(n);

  for(ii=0;ii<n;ii++){
    cin >> a[ii];
  }

  cin >> q;
  int ret;
  for(ii=0;ii<q;ii++){
    cin >> k;
    //ret = lower_bound(&a,k);
    cout << lower_bound(&a,k) << endl;
  }
  
  //for(ii=0;ii<q;ii++){
  //  cin >> k;
  //  if(binSearch(&a,k)){
  //    cout << "1" << endl;
  //  }
  //  else{
  //    cout << "0" << endl;
  //  }
  //}
  
  return 0;
}

