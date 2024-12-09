#include <iostream>
using namespace std;
int main(void){
    int h,a,b,x;
    x=0;
    cin>>h>>a>>b;
    for(int i=a;a<=b;a++){
        if(h%a==0)x++;
    }
    cout<<x<<endl;
}

