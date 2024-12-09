#include<iostream>
using namespace std;
int n,OUT,SCORE;
bool F,S,T;
string str;
int main(){
  cin>>n;
  while(n--){
    OUT=SCORE=0;
    F=S=T=false;
    while(OUT<3){
      cin>>str;
      if(str=="OUT")OUT++;
      else if(str=="HIT"){
	if(T){SCORE++;T=false;}
	if(S){T=true;S=false;}
	if(F){S=true;}
	F=true;
      }else if(str=="HOMERUN"){
	if(T)SCORE++;
	if(S)SCORE++;
	if(F)SCORE++;
	SCORE++;
	T=S=F=false;
      }
    }
    cout<<SCORE<<endl;
  }
  return 0;
}