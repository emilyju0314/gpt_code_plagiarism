#include<iostream>
using namespace std;

string str;
int tf[52];

bool update(string x){
  for(int i=0;i<52;i++)tf[i] = 0;
  for(int i=0;i<(int)x.size();i++){
    if(x[i]!='&'){
      int tmp;
      if(x[i] == '~'){
	if(x[i+1]>='a' && x[i+1]<='z')tmp = x[i+1]-'a';
	else tmp = x[i+1]-'A'+26;
	if(!tf[tmp])tf[tmp] = -1;
	else if(tf[tmp] == 1)return false;
	i++;
      }else{
	if(x[i]>='a' && x[i]<='z')tmp = x[i]-'a';
	else tmp = x[i]-'A'+26;
	if(!tf[tmp])tf[tmp] = 1;
	else if(tf[tmp] == -1)return false;
      }
    }
  }
  return true;
}

bool solve(void){
  string tmp;
  int pos = 0;
  while(pos < (int)str.size()){
    if(str[pos]=='|'){
      //cout << tmp << endl;
      if(update(tmp))return true;
      tmp.clear();
    }else if(str[pos]!='(' && str[pos]!=')')tmp.push_back(str[pos]);
    pos++;
  }
  if(update(tmp))return true;
  return false;
}
int main(){
  while(1){
    cin >> str;
    if(str == "#")break;

    if(solve())cout << "yes" << endl;
    else cout << "no" << endl;
  }
}