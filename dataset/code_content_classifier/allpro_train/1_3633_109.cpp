#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long  ll;

ll counter(ll from,ll to,ll mod){
  return to/mod-from/mod+(from%mod==0);
}

int main(){
  ll  s;
  cin>>s;
  ll ten[19];
  ten[0]=1;
  for(int i=1;i<19;i++){
    ten[i]=ten[i-1]*10;
  }
  ll lb=1;
  ll ub=s+1;
  ll cnt=0;
  bool isloop=true;
  //lb-1madenis-1moji
  while(isloop){
    if(ub-lb<=1){
      isloop=false;
    }
    ll mid=(lb+ub)/2;
    //mid made kazoeru
    cnt=0;
    int size;
    for(int i=0;i<19;i++){
      if(mid<ten[i+1]){
	size=i;
	break;
      }
      //ten[i+1]-1 to ten[i]
      ll cnt3=counter(ten[i],ten[i+1]-1,3);
      ll cnt5=counter(ten[i],ten[i+1]-1,5);
      ll cnt15=counter(ten[i],ten[i+1]-1,15);
      ll non=cnt3+cnt5-cnt15;
      cnt+=(ten[i+1]-ten[i]-non)*(i+1)+(cnt3+cnt5)*4;
    }
    ll cnt3=counter(ten[size],mid,3);
    ll cnt5=counter(ten[size],mid,5);
    ll cnt15=counter(ten[size],mid,15);
    ll non=cnt3+cnt5-cnt15;
    cnt+=(mid-ten[size]+1-non)*(size+1)+(cnt3+cnt5)*4;
    if(cnt<=s){
      lb=mid;
    }
    else{
      ub=mid;
    }

  }
  
  string res="";
  for(ll i=lb;res.size()<100;i++){
    if(i%3==0 && i%5==0){
      res+="FizzBuzz";
    }
    else if(i%3==0){
      res+="Fizz";
    }
    else if(i%5==0){
      res+="Buzz";
    }
    else{
      res+=to_string(i);
    }
  }
  int hoge=0;
  ll i=lb;
  if(i%3==0 || i%5==0){
    if(i%3==0){
      hoge+=4;
    }
    if(i%5==0){
      hoge+=4;
    }
  }
  else{
    hoge+=to_string(i).size();
  }
  
  cout<<res.substr(s-(cnt-hoge)-1,20)<<endl;
  return 0;
}