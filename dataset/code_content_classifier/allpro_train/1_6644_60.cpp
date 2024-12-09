#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> task[2*100000+10];
int t=0,N;
signed main(){
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> task[i].second >> task[i].first;
  }
  sort(task,task+N);
  for(int i=0;i<N;i++){
    t+=task[i].second;
    if(t<=task[i].first);
    else{
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
