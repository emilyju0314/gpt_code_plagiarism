#include<bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  map<string,int> poll;
  int max = 0;
  for(int i=0; i<N; i++) {
    string a;
    cin >> a;
    poll[a]++;
    if(poll[a] > max) max = poll[a];
  }
  for(auto x : poll) {
    if(x.second == max) {
      cout << x.first << endl;
    }
  }
}

