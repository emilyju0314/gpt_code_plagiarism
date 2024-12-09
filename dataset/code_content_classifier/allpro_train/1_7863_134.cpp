#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
  string S;
  cin>>S;
  for(int i=S.size()-1; i>=0; ){
    string T="";
    for(int j=i,k=0; k<7; k++,j--){
      T+=S[j];
      
      if(T=="esare"||T=="maerd"){
       
	i-=5;
	break;
      }
      else if(T=="resare"){
    
	i-=6;
	break;
      }
      else if(T=="remaerd"){
	i-=7;
	break;
      }
      else if(k==6||j==0){
	cout<<"NO"<<endl;
	return 0;
      }
    }
  }
  cout<<"YES"<<endl;
}
