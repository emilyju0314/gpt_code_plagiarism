#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,max,min;
    while(cin>>a>>b>>c){
    max=a;min=a;
    if(a>b)
    {
        min=b;
    }
    if(min>c){
        min=c;
    }
    if(max<b)
    max=b;
    if(max<c)
    max=c;
    cout<<min<<" "<<max<<endl;
}
    
}
