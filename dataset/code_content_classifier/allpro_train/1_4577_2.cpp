#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 151220;

int n;
bool able[MAX];
vector<int> V1;
vector<int> V2;

void make(){

  for(int i = 0; i*i*i < MAX; i++)
    V1.push_back(i*i*i);

  for(int i = 0; (i*(i+1)*(i+2))/6 < MAX; i++)
    V2.push_back((i*(i+1)*(i+2))/6);

  able[0] = true;

  for(int i = 0; i < V1.size(); i++)
    for(int j = 0; j < V2.size(); j++)
      if(V1[i]+V2[j] < MAX) able[V1[i]+V2[j]] = true; 
 
}

int solve(){

  for(int i = n; i >= 0; i--)
    if(able[i]) return i;

}

int main(){
  make();
  while(cin >> n && n) cout << solve() << endl;
  return 0;
}