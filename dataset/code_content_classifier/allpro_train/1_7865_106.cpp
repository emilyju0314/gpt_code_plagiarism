#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;int main(){string s;int n;map<string,set<int> >z;map<string, set<int> >::iterator q;set<int>::iterator x;while(cin>>s>>n)z[s].insert(n);for(q=z.begin();q!=z.end();){s=q++->first;cout<<s<<endl;for(x=z[s].begin(),n=0;x!=z[s].end();){if(n++)cout<<" ";cout<<*x++;}cout<<endl;}return 0;}