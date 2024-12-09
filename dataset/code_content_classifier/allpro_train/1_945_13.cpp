#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
 
typedef pair<int,int> P;
const int MAX=1000000000;
 
int main() {
  int L,n;
  cin >> L >> n;
  map<int,P> a;
  map<int,int> m;
  for(int i=0; i<n; i++) {
    int x,y,z;
    cin >> x >> y >> z;
    a[x].first=y;
    a[x].second=z;
    m[x]=MAX;
    m[x+y]=MAX;
  }
  m[L]=MAX;
  m[0]=0;
  map<int,int>::iterator it=m.begin();
  while(it!=m.end() && it->first<L) {
    map<int,int>::iterator now=it++;
    int i=now->first,j=it->first;
    m[j]=min(m[j],m[i]+(j-i));
    if(a[i].first) m[i+a[i].first]=min(m[i+a[i].first],now->second+a[i].second);
  }
  cout << m[L] << endl;
  return 0;
}
