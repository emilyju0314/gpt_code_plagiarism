#include<iostream>
using namespace std;
int main(){
    int a[101]={}, b, count=0;
    for(int i=0;i<12;i++){
        cin>>b;
        a[b-1]++;
    }
    for(int i=0;i<100;i++){
        if(a[i]==4) count++;
        if(a[i]==8) count += 2;
        if(a[i]==12) count += 3;
    }
    if(count == 3) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}

