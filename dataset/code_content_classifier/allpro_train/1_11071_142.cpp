#include<bits/stdc++.h>
using namespace std;
int v[]={6000,4000,3000,2000};
int main(){
    for(int i=0;i<4;i++){
        int a,b;cin>>a>>b;
        cout<<v[--a]*b<<endl;
    }
    return 0;
}