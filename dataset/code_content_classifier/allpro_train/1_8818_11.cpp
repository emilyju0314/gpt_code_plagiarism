#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int gdc(int a,int b){
    if(a%b==0)return b;
    return gdc(b,a%b);
}
void yaku(int a,int b){
    int g=gdc(max(a,b),min(a,b));
    cout<<a/g<<'/'<<b/g<<endl;
}
int main(void){
    char s[9];
    cin>>s;
    int k=10,x=0,l=strlen(s),i;
    for(i=0;s[i]!='.';i++){
        x*=10;
        x+=int(s[i]-'0');
    }
    int m=1;
    for(i++;s[i]!='(';i++,k*=10,m*=10){
        x*=10;
        x+=int(s[i]-'0');
        if(i==l-1){
            yaku(x,k);
            return 0;
        }
    }
    int y=x;
    for(i++;s[i]!=')';i++,k*=10){
        x*=10;
        x+=int(s[i]-'0');
        
    }
    k/=10;
    yaku(x-y,k-m);
}