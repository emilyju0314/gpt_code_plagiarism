#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        bool flag=false;
        int count=0,pal=0;
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i]){
                flag=true;
                pal++;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                count++;
            }
        }
        if(flag==false){
            if(count==1 || count%2==0){
                cout<<"BOB"<<endl;
            }
            else{
                cout<<"ALICE"<<endl;
            }
        }
        else{
            if(count==2 && pal==1){
                cout<<"DRAW"<<endl;
            }
            else{
                cout<<"ALICE"<<endl;
            }
        }
    }
}