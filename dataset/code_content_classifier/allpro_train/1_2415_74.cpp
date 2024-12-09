#include<iostream>
using namespace std;
int main(){

  int a,b,cnt,cnt2=0;

  while(1){
    
    cin >>a>>b;
    if(a == 0 && b == 0)break;
    if( cnt2 != 0 )cout <<endl;
    cnt2++;
    cnt=0;
    
    for(int i=a; i <= b ; i++){
      
      if( i % 100 == 0 && i % 400 != 0 )continue;
      
      else{
	
	if( i%4 == 0 ){
	  cout <<i<<endl;
	  cnt++;
	}
	
      }
      
    }
    
    if(cnt ==0){
      cout <<"NA"<<endl;
    }

   
    
  }
  return 0;
}