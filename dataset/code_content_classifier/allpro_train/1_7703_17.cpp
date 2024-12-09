#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
  int n,w;
  set<int> s;
  vector<int> f;

  cin >> n >> w;
  cout << w << (w==n?"\n":" ");
  for(int i=1;i<=w;i++)s.insert(i);

  for(int z=w+1;z<=n;z++){
    int prv = z-w;
    f.clear();
    for(int i=1;i*i<=prv;i++){
      if(prv%i==0){
	f.push_back(i);
	if(i*i!=prv)f.push_back(prv/i);
      }
    }

    for(int i=0;i<f.size();i++){
      if(s.find(f[i])==s.end())continue;
      int pre = (prv+1)/f[i];
      if((prv+1)%f[i]!=0)pre++;
      int suf = (z-1)/f[i];
      if(suf-pre<=0)s.erase(f[i]);
    }

    f.clear();
    for(int i=1;i*i<=z;i++){
      if(z%i==0){
	f.push_back(i);
	if(i*i!=z)f.push_back(z/i);
      }
    }

    s.insert(z);
    for(int i=0;i<f.size();i++){
      if(s.find(f[i])!=s.end())continue;
      int pre = (prv+1)/f[i];
      if((prv+1)%f[i]!=0)pre++;
      int suf = (z-1)/f[i];
      if(suf-pre>=0)s.insert(f[i]);
    }

    cout << s.size() << (z==n?"\n":" ");
  }
}
    