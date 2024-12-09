#include<iostream>
#include<math.h>
using namespace std;
int n,y,b,r,t,mxno;
double mx,x;
double tanri(){
  return 1.0+(double)y*(double)r/100.0;
}
double hukuri(){
  return pow((1.0+(double)r/100.0),y);
}
int main(){
  while(1){
    cin>>n;
    if(n==0)break;
    cin>>y;
    mx=0.0;
    mxno=0;
    for(int i=0;i<n;i++){
      cin>>b>>r>>t;
      if(t==1){
	x=tanri();
	//cout<<x<<endl;
	if(x>mx){
	  mx=x;
	  mxno=b;
	}
      }else{
	x=hukuri();
	//cout<<x<<endl;
	if(x>mx){
	  mx=x;
	  mxno=b;
	}
      }
    }
    cout<<mxno<<endl;
  }
  return 0;
}