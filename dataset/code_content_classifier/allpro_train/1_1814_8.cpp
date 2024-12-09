#include<iostream>
#include<memory>
#include<cstdio>

using namespace std;

int rest;
int leak;

struct M{
  int size;
  M(int c):size(c){
    rest-=c;
  }
  ~M(){
    leak+=size;
  }
};

typedef shared_ptr<M> P;


P ptr[128];
char line[301];
char *p;

P expr(){
  if(*p=='('){
    p++;
    P r=expr();
    p++;
    return r;
  }else if(*p=='m'){
    p+=7;
    int r,n;
    sscanf(p,"%d%n",&r,&n);
    p+=n+1;
    if(r>rest){
      return nullptr;
    }else{
      return P(new M(r));
    }
  }else if(*p=='c'){
    p+=6;
    P r=expr();
    p++;
    if(r){
      if(r->size==0)throw 0;
      if(rest<r->size){
	return nullptr;
      }else{
	return P(new M(r->size));
      }
    }else{
      return nullptr;
    }
  }else if(p[1]=='U'){
    p+=4;
    return nullptr;
  }else{
    char c=*p;
    p++;
    if(*p!='='){
      return ptr[c];
    }else{
      p++;
      return ptr[c]=expr();
    }
  }
}

void l(){
  if(*p=='f'){
    p+=5;
    P r=expr();
    p++;
    if(r){
      if(r->size==0)throw 0;
      rest+=r->size;
      r->size=0;
    }
  }else{
    expr();
  }
}

int main(){
  cin>>rest;
  for(auto &e:ptr){
    e=P(new M(0));
  }
  try{
    while(cin>>line){
      p=line;
      l();
    }
    cout<<leak<<endl;
  }catch(...){
    cout<<"Error"<<endl;
  }
}