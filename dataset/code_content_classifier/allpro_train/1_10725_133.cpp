#include<iostream>
using namespace std;

int main(){

    int e,y;

    cin >> e >> y;

    if(e==0){
      if(y <= 1911){
        cout << 'M' << y-1868+1 << endl;
      }
      else if(y >= 1912 && y <= 1925){
        cout << 'T' << y-1912+1 << endl;
      }
      else if(y >= 1926 && y <= 1988){
        cout << 'S' << y-1926+1 << endl;
      }
      else{
        cout << 'H' << y-1989+1 << endl;
      }
    }
    else if(e==1){
      cout << y+1868-1 << endl;
    }
    else if(e==2){
      cout << y+1912-1 << endl;
    }
    else if(e==3){
      cout << y+1926-1 << endl;
    }
    else{
      cout << y+1989-1 << endl;
    }
    
    return 0;
}