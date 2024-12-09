#include<iostream>
#include<cstdio>
using namespace std;

int main(){

  int n;
  char c;

  while(cin>>n>>c){
    if(1<=n && n<=9){
      switch(n){
      case 1 : break;
      case 2 : cout<<'k'; break;
      case 3 : cout<<'s'; break;
      case 4 : cout<<'t'; break;
      case 5 : cout<<'n'; break;
      case 6 : cout<<'h'; break;
      case 7 : cout<<'m'; break;
      case 8 : cout<<'y'; break;
      case 9 : cout<<'r'; break;
      }
      switch(c){
      case 'T' : cout<<'a'; break;
      case 'L' : cout<<'i'; break;
      case 'U' : cout<<'u'; break;
      case 'R' : cout<<'e'; break;
      case 'D' : cout<<'o'; break;
      }
    }
    else if(n==0){
     switch(c){
     case 'T' : cout<<'w'<<'a'; break;
     case 'L' : break;
     case 'U' : cout<<'n'<<'n'; break;
     case 'R' : break;
     case 'D' : cout<<'w'<<'o'; break;
     }
   }
  }
  puts("");
  return 0;
}