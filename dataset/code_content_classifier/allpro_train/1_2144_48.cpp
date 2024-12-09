#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w,n;
    cin>>h>>w>>n;
    cout<<min((n+w-1)/w,(n+h-1)/h)<<endl;
    return 0;
}
