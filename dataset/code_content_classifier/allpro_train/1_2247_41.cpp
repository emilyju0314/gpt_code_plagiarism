#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(){

  vector<string> vs;
  map<string,int> dict;

  int idx=0;
  vs.push_back("Rock");dict["Rock"]=idx++;
  vs.push_back("Fire");dict["Fire"]=idx++;
  vs.push_back("Scissors");dict["Scissors"]=idx++;
  vs.push_back("Snake");dict["Snake"]=idx++;
  vs.push_back("Human");dict["Human"]=idx++;
  vs.push_back("Tree");dict["Tree"]=idx++;
  vs.push_back("Wolf");dict["Wolf"]=idx++;
  vs.push_back("Sponge");dict["Sponge"]=idx++;
  vs.push_back("Paper");dict["Paper"]=idx++;
  vs.push_back("Air");dict["Air"]=idx++;
  vs.push_back("Water");dict["Water"]=idx++;
  vs.push_back("Dragon");dict["Dragon"]=idx++;
  vs.push_back("Devil");dict["Devil"]=idx++;
  vs.push_back("Lightning");dict["Lightning"]=idx++;
  vs.push_back("Gun");dict["Gun"]=idx++;
  int n;
  while(cin>>n&&n!=0){
    string str;
    vector<string> hands;
    for(int i = 0; i < n; i++){
      cin>>str;
      hands.push_back(str);
    }
    bool w=false;
    for(int i = 0; i < n; i++){
      int win=0;
      int lose=0;
      int drow=0;
      int iidx=dict[hands[i]];
      for(int j = 0; j < n; j++){
	if(i==j)continue;
	// jÌèÌêðTµÄ«ÄA»ÌêÉ¶Ä
	int jidx=dict[hands[j]];
	if(iidx==jidx){
	  drow++;
	  continue;
	}
	int prv,nxt;
	// är³ÌidxÌÙ¤ª¬³¢ê
	if(iidx<jidx){
	  prv=jidx-iidx;
	  nxt=iidx+1+(vs.size()-1-jidx);
	}
	else{
	  prv=vs.size()-1-iidx+jidx+1;
	  nxt=iidx-jidx;
	}
	if(prv<nxt)
	  win++;
	else{
	  lose++;
break;
}
      }
      //cout<<"win:"<<win<<"lose:"<<lose<<"draw:"<<drow<<endl;
      if(lose>0)
	continue;
      else if(win>=1){
	// win
	w=true;
	cout<<hands[i]<<endl;
	break;
      }
    }
    if(!w){
      cout<<"Draw"<<endl;
    }
  }

  return 0;
}