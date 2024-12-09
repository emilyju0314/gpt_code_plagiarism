#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B;cin>>A>>B;
  cout<<"100 100"<<endl;
  vector<string>S(100);

  for(int i=0;i<50;i++)S[i]=string(100,'#');
  for(int i=50;i<100;i++)S[i]=string(100,'.');

  for(int i=0;i<A-1;i++)S[2*(i/50)][(i%50)*2]='.';
  for(int i=0;i<B-1;i++)S[51+2*(i/50)][(i%50)*2]='#';

  for(int i=0;i<100;i++)cout<<S[i]<<endl;
}

/*






*/