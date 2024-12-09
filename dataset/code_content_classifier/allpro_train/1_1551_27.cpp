#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<tuple>
#include<algorithm>
#include<numeric>
#include<set>

using namespace std;

int main(){
  for(int n;cin>>n,n;){
    vector<tuple<string,string,char,int> > v;
    map<string,int> s,b;
    map<char,vector<int> > c;
    set<string> names;
    for(int i=0;i<n;i++){
      string name,o;
      char com;
      int p;
      cin>>name>>o>>com>>p;
      names.insert(name);
      if(o=="BUY"){
	int x=-1;
	for(int j=0;j<v.size();j++){
	  if(get<0>(v[j])!=name&&get<1>(v[j])!=o&&get<2>(v[j])==com&&get<3>(v[j])<=p&&(x<0||get<3>(v[j])<get<3>(v[x]))){
	    x=j;
	  }
	}
	if(x<0){
	  v.emplace_back(name,o,com,p);
	}else{
	  int m=(p+get<3>(v[x]))/2;
	  s[get<0>(v[x])]+=m;
	  b[name]+=m;
	  c[com].push_back(m);
	  v.erase(begin(v)+x);
	}
      }else{
	int x=-1;
	for(int j=0;j<v.size();j++){
	  if(get<0>(v[j])!=name&&get<1>(v[j])!=o&&get<2>(v[j])==com&&get<3>(v[j])>=p&&(x<0||get<3>(v[j])>get<3>(v[x]))){
	    x=j;
	  }
	}
	if(x<0){
	  v.emplace_back(name,o,com,p);
	}else{
	  int m=(p+get<3>(v[x]))/2;
	  b[get<0>(v[x])]+=m;
	  s[name]+=m;
	  c[com].push_back(m);
	  v.erase(begin(v)+x);
	}
      }
    }
    for(auto e:c){
      cout<<e.first<<' '<<*min_element(begin(e.second),end(e.second))<<' '<<accumulate(begin(e.second),end(e.second),0)/e.second.size()<<' '<<*max_element(begin(e.second),end(e.second))<<endl;
    }
    cout<<"--"<<endl;
    for(auto e:names){
      cout<<e<<' '<<b[e]<<' '<<s[e]<<endl;
    }
    cout<<"----------"<<endl;
  }
}