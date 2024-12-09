#include<cstdlib>
#include<cstdio>
#include<string>
#include<sstream>
#include<cassert>
#include<iostream>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb         push_back
string pre_processing(string &in);
string pre_processing2(string &in);

class Element{
public:
  int c;
  int p[26];
  Element(){
    c=0;rep(i,26)p[i]=0;
  }
};

typedef vector<Element> formula;
Element ori;


bool is_same_Element(Element a,Element b){
  rep(i,26)if (a.p[i] != b.p[i])return false;
  return true;
}


void erase_duplicate(formula &ret){
  rep(i,ret.size()){
    REP(j,i+1,ret.size()){
      if (is_same_Element(ret[i],ret[j])){
	ret[i].c+=ret[j].c;
	ret.erase(ret.begin()+j);
	j--;
      }
    }
  }
  rep(i,ret.size()){
    if (ret[i].c == 0){
      ret.erase(ret.begin()+i);
      i--;
    }
  }
  //if (ret.size() == 0)ret.pb(ori);
}

bool is_same_formula(formula a,formula b){
  erase_duplicate(a);
  erase_duplicate(b);
  if (a.size() != b.size())return false;
  if (a.size() == 1 && b.size() == 1){
    //if (a[0].c == 0 && b[0].c == 0)return true;
  }

  rep(i,a.size()){
    bool canfind=false;
    if (a[i].c == 0)continue;
    rep(j,b.size()){
      if (is_same_Element(a[i],b[j]) &&
	  a[i].c == b[j].c){
	b.erase(b.begin()+j);
	canfind=true;
	break;
      }
    }
    if (!canfind)return false;
    
  }
  if (b.size() == 0)return true;
  else return false;
}

formula mult(formula a,formula b){
  formula ret;
  rep(i,a.size()){
    if (a[i].c == 0)continue;
    rep(j,b.size()){
      if (b[j].c == 0)continue;
      Element tmp;
      tmp.c=a[i].c*b[j].c;
      rep(k,26){
	tmp.p[k]=a[i].p[k]+b[j].p[k];
      }
      ret.pb(tmp);
    }
  }
  erase_duplicate(ret);
  return ret;
}

formula plu(formula a,formula b){
  formula ret;
  rep(i,a.size())if (a[i].c !=0)ret.pb(a[i]);
  rep(i,b.size())if (b[i].c !=0)ret.pb(b[i]);
  erase_duplicate(ret);
  return ret;
}

formula minu(formula a,formula b){
  formula ret;
  rep(i,a.size())if (a[i].c!=0)ret.pb(a[i]);
  rep(i,b.size()){
    if (b[i].c != 0){
      Element tmp = b[i];
      tmp.c*=-1;
      ret.pb(tmp);
    }
  }
  erase_duplicate(ret);
  return ret;
}

void output(formula a){
  cout <<"output begin"<<endl;
  rep(i,a.size()){
    cout << a[i].c ;
    rep(j,26){
      if (a[i].p[j]==0)continue;
      cout << (char)(j+'a') <<"^"<<
	a[i].p[j];
    }
    cout << endl;
  }
  cout <<"output end" << endl;
}

formula term(string &in,int &p);
formula fact(string &in,int &p);
formula digit(string &in,int &p);
int       num(string &in,int &p);

formula fact(string &in,int &p){
  formula ret=term(in,p);
  while(p < in.size()){
    if (in[p] == '+'){
      p++;
      formula tmp = term(in,p);
      ret=plu(ret,tmp);
    }else if (in[p]=='-'){
      p++;
      formula tmp = term(in,p);
      ret=minu(ret,tmp);
    }else break;
  }
  return ret;
}

formula term(string &in,int &p){
  formula ret = digit(in,p);
  while(p < in.size()){
    if (in[p] == '*'){
      p++;
      formula tmp = digit(in,p);
      ret=mult(ret,tmp);
    }else if (in[p] == '('||isdigit(in[p])||
	     isalpha(in[p])){
      formula tmp = digit(in,p);
      ret=mult(ret,tmp);
    }else break;
  }
  return ret;
}

formula digit(string &in,int &p){
  formula ret;
  if(in[p] == '('){
    p++;
    ret=fact(in,p);
    p++;//skip ')'
  }else if (isdigit(in[p])){
    int tmp = num(in,p);
    Element ins;
    ins.c=tmp;
    ret.pb(ins);
  }else if (isalpha(in[p])){
    Element tmp;
    tmp.c=1;
    tmp.p[in[p]-'a']++;
      p++;
    ret.pb(tmp);
  }

  if (p < in.size() && in[p]=='^'){
    formula ori = ret;
    p++;
    int power=num(in,p);
    Element tmp;
    tmp.c=1;
    ret.clear();
    ret.pb(tmp);
    rep(i,power){
      ret=mult(ret,ori);
    }
  }
  return ret;
}

int num(string &in,int &p){
  int tmp=0;
  while(p < in.size() && isdigit(in[p])){
    tmp=(tmp*10)+(in[p]-'0');
    p++;
  }
  return tmp;
}

int main(){
  string in;
  while(getline(cin,in) && in != "."){
    string tmp=in;
    in = pre_processing(in);
    int p=0;

    formula me = fact(in,p);
    //    cout << "formula :" << in << endl;output(me);
    string cmp;

    while(getline(cin,cmp) && cmp != "."){
      tmp=cmp;
      cmp=pre_processing(cmp);
      p=0;
      formula you = fact(cmp,p);

      if (is_same_formula(me,you))cout <<"yes"<<endl;
      else cout <<"no"<<endl;
    }
    cout << "."<<endl;
  }
  return false;
}



string pre_processing(string &in){
  bool last=false;
  int prev=-2;
  string ret="";
  rep(i,in.size()){
    if (in[i] == ' ')continue;
    if (isdigit(in[i])||isalpha(in[i])){
      if (i!=0&&in[i-1]==' '&&last==true)ret+='*';
      last=true;
    }else last=false;
    ret+=in[i];
  }
  return ret;
}
/*
string pre_processing2(string &in){
  bool last=false;
  int prev=-2;
  string ret="",tmp;
  stringstream sin(in);
  sin>>ret;
  while(sin>>tmp){
    int p=ret.size()-1;
    if (tmp[0] == '+'){
      ret+=tmp;
    }else if (tmp[0] == '-'){
      ret+=tmp;
    }else if (tmp[0] =='('){
      if (ret[p] == ')'){
	ret=ret+'*'+tmp;
      }else if (isdigit(ret[p])){
	ret=ret+'*'+tmp;
      }else if (isalpha(ret[p])){
	ret=ret+'*'+tmp;
      }else ret+=tmp;
    }else if (tmp[0] == ')'){
      ret+=tmp;
    }else if (tmp[0] == '^'){
      ret+=tmp;
    }else if (isdigit(tmp[0])){
      if (ret[p] == ')'){
	ret=ret+'*'+tmp;
      }else if (isdigit(ret[p])){
	ret=ret+'*'+tmp;
      }else if (isalpha(ret[p])){
	ret=ret+'*'+tmp;
      }else ret+=tmp;
    }else if (isalpha(tmp[0])){
      if (ret[p] == ')'){
	ret=ret+'*'+tmp;
      }else if (isdigit(ret[p])){
	ret=ret+'*'+tmp;
      }else if (isalpha(ret[p])){
	ret=ret+'*'+tmp;
      }else ret+=tmp;
    }
  }
  return ret;
}
*/