#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int a;
  int b=0;
  int c[8],d[8];
  int h,l;
  while(true){
    b=0;
    cin>>a;
    if(a==0000){
      break;
    }
    while(true){
      if(a==6174){
	cout<<b<<"\n";
	break;
      }
      if(a==0){
	cout<<"NA\n";
	break;
      }
      for(int i=0;i<4;i++){
	c[i]=a%10;
	a=a/10;
	d[i]=c[i];
      }
      sort(c,c+4);
      sort(d,d+4,greater<int>());
      for(int i=0;i<4;i++){
	if(i==0){
	h=c[i]*1000;
	l=d[i]*1000;
	}
	if(i==1){
	   h=c[i]*100+h;
	   l=d[i]*100+l;
	}
	if(i==2){
	  h=c[i]*10+h;
	  l=d[i]*10+l;
	}
	if(i==3){
	  h=c[i]+h;
	  l=d[i]+l;
	}
      }
      a=l-h;
      b++;
    }
  }
  return(0);
}

