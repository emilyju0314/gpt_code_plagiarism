#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  while(cin >> n >> k, n){
    vector<string> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    sort(a.begin(), a.end());

    set<string> ans;
    for(int bit=1;bit<(1<<n);bit++){
      if(__builtin_popcount(bit) == k){
        vector<string> use;
        for(int i=0;i<n;i++){
          if( (bit>>i)&1 ) use.push_back(a[i]);
        }
        do{
          string con;
          for(int i=0;i<k;i++) con += use[i];
          ans.insert(con);
        }while( next_permutation(use.begin(), use.end()) );
      }
    }
    cout << ans.size() << endl;
  }
}