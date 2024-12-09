#include <bits/stdc++.h>
using namespace std;

int main() {
  long q,query,a,b,nowans2=0;
  cin >> q;
  multiset<long> adata;
  vector<long> ans1,ans2;

  cin >> query >> a >> b;
  adata.insert(a);
  auto itr=adata.begin();
  nowans2+=b;

  for(long i=1;i<q;i++) {
    cin >> query;
    if(query==1) {
      cin >> a >> b;
      nowans2+=b;
      if(adata.size()%2==0) {
        long aaa=*(itr);
        itr++;
        long bbb=*(itr);
        itr--;
        adata.insert(a);
        if(a<aaa) nowans2+=aaa-a;
        else if(a>bbb) nowans2+=a-bbb;
        if(a>=aaa) itr++;
      } else {
        adata.insert(a);
        nowans2+=labs(a-*(itr));
        if(a<*(itr)) itr--;
        
      }
    } else {
      ans1.push_back(*(itr));
      ans2.push_back(nowans2);
    }
  }
  for(long i=0;i<ans1.size();i++) cout << ans1[i] << " " << ans2[i] << endl;
}