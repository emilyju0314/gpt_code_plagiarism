#include<bits/stdc++.h>
using namespace std;
int N;
int num[256];
vector<char> mum[11];
int main(){
  cin >> N;
  for(int i=0;i<N;i++){
    char n;
    cin >> n;
    if( !(i&1) ) num[n]++;
  }
  for(int i='a';i<='z';i++){
    if( num[i] == 0 ) continue;
    //cout << (char)i << " "<< num[i] << endl;
    mum[num[i]].push_back( i );
  }
  bool f = false;
  int res = 0;
  for(int i=1;i<10;i++){
    //cout << mum[i].empty() << " "<<f << " " << i << " " << res << endl;
    if( mum[i].empty() ) continue;
    if( f ) res++;
    if( mum[i].size() == 1){      
      if( i == 1 ) res++;
      else res+=3;
    } else {
      if( i== 1 ) {
	for(int j=0;j<mum[i].size();j++){
	  if( j ) res++;
	  res++;
	}
      } else {
	res+=3;
	for(int j=0;j<mum[i].size();j++){
	  if( j ) res++;
	  res++;	  
	}
	res++;
      }
    }

    f = true;
  }
  cout <<res << endl;
}