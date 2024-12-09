#include<iostream>
#include<string>
#include<map>
#include<set>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
string s;
int n,flag,x,p;
char c;
map<char,int>m;
int bnf1();
int get_A(){
  int res=0;
  if(s[p]=='[')p++,res=bnf1(),p++;
  else res=m[s[p++]];
  return res;
}
int bnf1(){
  int res=get_A();
  while(s[p]=='-'){
    int t=p++;
    int x=get_A();
    if(x&&res)flag++;
    if(!x&&!res)flag++;
    res=max(res,x)-1;
  }
  return res;
}
int main(){
  cin>>s;
  set<char>st;
  r(i,s.size())if(isalpha(s[i]))st.insert(s[i]);
  n=st.size();
  r(i,n){
    cin>>c>>x;
    m[c]=x;
  }
  if(bnf1()!=0)flag++;
  cout<<(flag?"No":"Yes")<<endl;
}