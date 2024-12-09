#include<bits/stdc++.h>
using namespace std;

bool check(string s){
  if( s == "ABC" ){
    return true;
  }
  if( s.size() <= 3 ){
    return false;
  }


  string t="";
  for(int i=0;i<s.size();){
    
    if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
      t+='X';
      i+=3;
    }else{
      t+=s[i];
      i++;
    }
  }
  
  int fa=0,fb=0,fc=0;
  for(int i=0;i<t.size();i++){
    if(t[i]=='A')fa=1;
    if(t[i]=='B')fb=1;
    if(t[i]=='C')fc=1;
  }
  
  if( s == t ){
    return false;
  }
  
  if(fa+fb+fc!=2){
    return false;
  }

  for(int i=0;i<t.size();i++){
    if(t[i]=='X'){
      if(fa==0)t[i]='A';
      if(fb==0)t[i]='B';
      if(fc==0)t[i]='C';
    }
  }

  return check(t);
}

int main(){
  string s;
  cin>>s;
  if( check(s) ){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}

