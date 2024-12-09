#include<iostream>
using namespace std;
int n,a,cnt1;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a%2)cnt1++;
    }
    cout<<(cnt1%2?"NO":"YES")<<endl;
}