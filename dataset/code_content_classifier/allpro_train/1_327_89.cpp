#include <iostream>
#include <utility>
using namespace std;

int main(void){

  int n,B[25],T[25],cnt,cnt2;

  while(1){
    
    cin >>n;

    if(n ==0)break;

    cnt=0;
    cnt2=0;

    for(int i=0 ; i < n ; i++){
      cin >>T[i]>>B[i];
    }

    for(int i=0 ; i < n ; i++){
      for(int j=1 ; j < n-i ; j++){
	if(B[j] > B[j-1]){
	  swap(B[j],B[j-1]);
	  swap(T[j],T[j-1]);
	}
      }
    }

   

    for(int i=n-1 ; 0 <= i ; i--){
      if(B[i] >= T[i]+cnt){
	cnt+=T[i];
	cnt2++;
      }else{
	cnt2=0;
	break;
      }
    }
    
    if(cnt2 == 0){
      cout <<"No"<<endl;
    }else{ 
      cout <<"Yes"<<endl;
    }   
  } 
  
  return 0;
}