#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
map<string,P> range;
stack<set<int> > num;

int getNum(string s){
  int res=0;
  for(int i=0;i<s.size();i++)
    res=res*10+s[i]-'0';
  return res;
}

int main(){
  int n,m,a,b;
  string s;
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>s>>a>>b;
    range[s]=P(a,b);
  }
  bool ans=false;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s;
    set<int> x;
    if('0'<=s[0]&&s[0]<='9'){
      x.insert(getNum(s));
      num.push(x);
    }
    else if('a'<=s[0]&&s[0]<='z'){
      P r=range[s];
      for(int j=r.first;j<=r.second;j++)
	x.insert(j);
      num.push(x);
    }else{
      set<int> B=num.top(); num.pop();
      set<int> A=num.top(); num.pop();
      set<int> C;
      set<int>::iterator i1=A.begin();
      while(i1!=A.end()){
	set<int>::iterator i2=B.begin();
	while(i2!=B.end()){
	  int n1=(*i1),n2=(*i2);
	  if(s=="+")C.insert((n1+n2)%256);
	  if(s=="-")C.insert((n1-n2+256)%256);
	  if(s=="*")C.insert((n1*n2)%256);
	  if(s=="/"){
	    if(!n2){
	      ans=true;
	      break;
	    }
	    C.insert((n1/n2)%256);
	  }
	  i2++;
	}
	if(ans)break;
	i1++;
      }
      if(ans)break;
      num.push(C);
    }
  }
  if(ans)cout<<"error"<<endl;
  else cout<<"correct"<<endl;
  return 0;
}