#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int main(){
  int n;
  while(cin >>n,n){
    vector<pair<int, int> > score;
    cin >>ws;
    for(int k=0; k<n; k++){
      vector<int> bowl;
      string s;
      int x = 0,sn,p=0;
      bool f = true;
      getline(cin,s);
      for(int i=0; i<s.size(); i++){
	if(s[i] == ' '){
	  if(f){sn = x;f = false;}
	  else{bowl.push_back(x);}
	  x = 0;
	}
	if(s[i]>='0' && s[i]<='9'){x = x*10+s[i]-'0';}
      }
      bowl.push_back(x);
      int a=0,b=0,c=0,d=0,e=2;
      for(int i=0; i<bowl.size(); i++){
	p+=bowl[i]*(a+1);
	d+=bowl[i];
	e--;
	a = b;
	b = 0;
	if(e == 1 && d == 10){
	  c++;
	  e = 2;
	  d = 0;
	  if(c<10){
	    a++;
	    b++;
	  }
	}
	if(e == 0){
	  c++;
	  e = 2;
	  if(d == 10 && c<10){a++;}
	  d = 0;
	}
      }
      score.push_back(make_pair(-p,sn));
    }
    sort(score.begin(),score.end());
    for(int i=0; i<score.size(); i++){
      cout<< score[i].second<<" "<<-score[i].first<<endl;
    }
  }
  return 0;
}