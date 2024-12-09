#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,i,j;
        cin>>n;
        int a[n],b[n],c=0;
        map<int,int> mp2;
        for(i=0; i<n; i++){
            cin>>a[i];
            if(a[i]!=b[c-1]){
                b[c]=a[i];
                c++;
            }
        }
        for(i=0;i<c;i++){
            mp2[b[i]]++;
        }
        if(c==1){
            cout<<0<<endl;
        }
        else{
            mp2[b[0]]--;
            mp2[b[c-1]]--;
            int m=1e9;
            for(auto i:mp2){
                if(i.second+1<m){
                    m=i.second+1;
                }
            }
        
            cout<<m<<endl;
        }
        
    }
}