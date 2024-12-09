//26
#include<iostream>
#include<set>
#include<string>
#include<vector>

using namespace std;

vector<string> rot(vector<string> d,int a,int b,int c,int x){
  string t=d[a];
  d[a]=d[b];
  d[b]=d[c];
  d[c]=d[x];
  d[x]=t;
  return d;
}

vector<string> rotu(vector<string> d){
  return rot(d,0,1,5,4);
}

vector<string> rotr(vector<string> d){
  return rot(d,3,0,2,5);
}

vector<string> roth(vector<string> d){
  return rot(d,1,2,4,3);
}

int main(){
  for(int n;cin>>n,n;){
    set<vector<string> > s;
    for(int i=0;i<n;i++){
      vector<string> d(6);
      for(int j=0;j<6;j++){
	cin>>d[j];
      }
      for(int j=0;j<6;j++){
	if(j%2){
	  d=rotu(d);
	}else{
	  d=rotr(d);
	}
	for(int k=0;k<4;k++){
	  d=roth(d);
	  s.insert(d);
	}
      }
    }
    cout<<n-s.size()/24<<endl;
  }
  return 0;
}