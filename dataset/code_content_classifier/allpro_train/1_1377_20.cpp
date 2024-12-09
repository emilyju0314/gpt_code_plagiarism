#include<iostream>
using namespace std;
bool t[1000001];
int  u[1000001];
int N =1000000;
int n,m;
void make_table(){
  for(int i=0;i<=N;i++){
    t[i]=false;
    u[i]=0;
  }

  t[1]=true;

  for(int i=1;i<=N;i++){
    u[i]=u[i-1];
    if(t[i]==false)continue;
    u[i]++;
    if(i*2<=N)t[i*2]=true;
    if(i*3<=N)t[i*3]=true;
    if(i*5<=N)t[i*5]=true;
  }
}



int main(){
  make_table();
  while(cin>>n>>m){
    cout<<u[m]-u[n]+t[n]<<endl;
  }
}