#include <iostream>
using namespace std;

int n,a[20];
int solve(int i,int m){
    if(m == 0) return true;
    if(i >= n) return false;
    int res = solve(i+1,m) || solve(i+1,m-a[i]);
    return res;
}
int main(){
    int q,M;    
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>q;
    int i=0;
    while(q--){
        cin>>M;
        if(solve(0,M))cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
