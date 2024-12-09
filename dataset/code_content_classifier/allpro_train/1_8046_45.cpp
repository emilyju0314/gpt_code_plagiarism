//suhan lee,saitama university

#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
#include <complex>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<  vector<double>  > vvd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
typedef complex<double> zahyo;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define repn(i,n) for(int i=0;i<n;i++)
#define EACH(t,i,c) for(t::iterator i=(c).begin(); i!=(c).end(); ++i)
#define pb push_back 
#define pf push_front
zahyo toshi[21];
double kyori[21][21];
double kakgyo[21][21];
int newdo[21][21][21];
bool newdotest(int i,int j,int k,double kakdo){
  if(newdo[i][j][k]!=100) return newdo[i][j][k];
  zahyo a=toshi[j]-toshi[i];
  zahyo b=toshi[k]-toshi[j];
  double kak= (a.real()*b.real()+a.imag()*b.imag())/  (abs(a)*abs(b));
  //cout<<kak<<endl;
  if (cos(kakdo*3.14159265/180.0)<=kak){
    newdo[i][j][k]=true;

  }
  else newdo[i][j][k]= false;
 
  return newdo[i][j][k];
}
bool kakdotest(zahyo a,zahyo b,double kakdo){
  double kak= (a.real()*b.real()+a.imag()*b.imag())/  (abs(a)*abs(b));
  if (cos(kakdo*3.14159265/180.0)<=kak)
    return true;
  else return false;
}
int main(){
  int n,k;
  double r,kakdo,xza,yza;
  cin>>n>>r>>kakdo;
  for(int i=1;i<=n;i++){
    cin>>xza>>yza;
    toshi[i]=zahyo(xza,yza);
  }
  for(int i=0;i<(n+1);i++)
    for(int j=0;j<(n+1);j++)
      for(int k=0;k<(n+1);k++)
	newdo[i][j][k]=100;
  
  for(int i=1;i<(n+1);i++)
	kyori[i][0]=abs(toshi[i]);
  for(int i=1;i<(n+1);i++)
    for(int j=1;j<(n+1);j++){
      kyori[i][j]=abs(toshi[i]-toshi[j]);
   
    }


  vvd nokori(n+1);
  for(int i=0;i<n+1;i++){
    nokori[i]=vector<double>(21,-1);
  }
  vvd prevnokori=nokori;
  for(int i=2;i<n+1;i++){
    prevnokori[1][i]=r-abs(toshi[i]-toshi[1]);
  }
  int maxcarrot=0;
  k=1;
  while(k-maxcarrot==1){
    vvd nextnokori=nokori;  
    for(int i=1;i<(n+1);i++)
      for(int j=1;j<(n+1);j++){
	if(i==j) continue;
	if(prevnokori[i][j]<0) continue;
	maxcarrot=k;
	//	cout<<i<<" "<<j<<" "<<k<<" "<<abs(prevnokori[i][j])<<endl;
	for(int l=1;l<(n+1);l++){
	  // if(kakdotest(toshi[i]-toshi[j],
	  // 	       toshi[j]-toshi[l],kakdo)){
	  if(newdotest(i,j,l,kakdo)){
	  nextnokori[j][l]=
	      max(prevnokori[i][j]-kyori[j][l],
				 nextnokori[j][l]);
	    //	    cout<<i<<" "<<j<<" "<<l<<endl;
	  }
	}

      }
    prevnokori=nextnokori;
    k++;
  }
  cout<<maxcarrot<<endl;

  return 0;
}