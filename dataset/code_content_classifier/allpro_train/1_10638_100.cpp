#include <iostream>
using namespace std;
int main(void){
    int a,b,c,d,e,f,g,h,i,j;
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    i=a*e+b*f;
    j=c*e+d*f;
    if(a/10>0){i=i+(a/10)*g;}
    if(c/10>0){j=j+(c/10)*g;}
    if(b/20>0){i=i+(b/20)*h;}
    if(d/20>0){j=j+(d/20)*h;}
    if(i>j){cout<<"hiroshi"<<endl;}else
    if(i<j){cout<<"kenjiro"<<endl;}else
    {cout<<"even"<<endl;}
}

