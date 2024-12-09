#include<iostream>
#include<stack>
#include<utility>
#include<cctype>

using namespace std;

typedef pair<long long,long long> PLL;

const int M=1000000007;
stack<PLL> num;
stack<char> op;

bool do2(){
  bool flag=false;
  while(!op.empty()){
    if(op.top()=='&'){
      auto r=num.top();
      num.pop();
      auto l=num.top();
      num.pop();
      auto t=(r.first*l.first)%M;
      num.push(PLL(t,((l.first+l.second)*(r.first+r.second)-t)%M));
    }else if(op.top()=='~'){
      auto r=num.top();
      num.pop();
      num.push(PLL(r.second,r.first));
    }else{
      break;
    }
    flag=true;
    op.pop();
  }
  return flag;
}

void do3(){
  while(!op.empty()){
    if(do2()){
    }else if(op.top()=='|'){
      auto r=num.top();
      num.pop();
      auto l=num.top();
      num.pop();
      auto f=(r.second*l.second)%M;
      num.push(PLL(((l.first+l.second)*(r.first+r.second)-f)%M,f));
      op.pop();
    }else{
      break;
    }
  }
}

int main(){
  char str[1000001];
  cin>>str;
  for(char *p=str;*p;){
    if(*p=='x'){
      num.push(PLL(1,1));
      p++;
      while(isdigit(*p)){
	p++;
      }
    }else{
      if(*p==')'){
	do3();
	op.pop();
      }else{
	if(*p=='|'){
	  do3();
	}else if(*p=='&'){
	  do2();
	}
	op.push(*p);
      }
      p++;
    }
  }
  do3();
  cout<<num.top().first<<endl;
}