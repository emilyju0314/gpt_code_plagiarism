#include<iostream>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;

typedef multimap<string, int>::iterator mmit;

int main(){
  
  int q, com, x;
  string key, l, r;
  multimap<string, int> M;
  
  cin >> q;
  for(int i = 0;i < q;i++){
    cin >> com;
    
    if(com == 0){
      cin >> key >> x;
      M.insert(make_pair(key, x));
    }else if(com == 1){
      cin >> key;
      pair<mmit, mmit> mit = M.equal_range(key);
      for(mmit it = mit.first;it != mit.second;it++) cout << it->second << endl;
    }else if(com == 2){
      cin >> key;
      M.erase(key);
    }else if(com == 3){
      map<string, int>::iterator itl, itr;
      
      cin >> l >> r;
      itl = M.lower_bound(l);
      itr = M.upper_bound(r);
      
      for(mmit it = itl;it != itr;it++) cout << it->first << " " << it->second << endl;
    }
  }
  
  return 0;
}
