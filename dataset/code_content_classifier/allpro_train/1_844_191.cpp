#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,k=1e9+7,a=0,b=0;string s;
    cin>>n>>s;
    vector<int> black(n);
    vector<int> white(n);
    for(int i=0;i<n;i++){
        if(s[i]=='#') a++;
        else b++;
        black[i]=a;white[i]=b;
    }
    for(int i=0;i<n;i++) k=min(k,black[i]+white[n-1]-white[i]);
    k=min(k,b);
    cout<<k;
}