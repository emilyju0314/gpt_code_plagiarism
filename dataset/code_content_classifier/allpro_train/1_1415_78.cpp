#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n,k;
    cin>>n>>k;
    vector<int> t(k),p(k);

    for(int i=0;i<k;i++){
        cin>>p[i];
    }
    for(int i=0;i<k;i++){
        cin>>t[i];
    }

    vector<int> forward(n);
    vector<int> reverse(n);
    vector<int> abc(n,INT_MAX);
    for(int i=0;i<k;i++){
        abc[p[i]-1]=t[i];
    }
    int prev=INT_MAX;

    for(int i=0;i<n;i++){
        forward[i]=min(prev,abc[i]);
        if(forward[i]!=INT_MAX){
            prev=forward[i]+1;
        }
    }
    prev=INT_MAX;
    for(int i=n-1;i>=0;i--){
        reverse[i]=min(prev,abc[i]);
        if(reverse[i]!=INT_MAX){
            prev=reverse[i]+1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<min(reverse[i],forward[i])<<" ";
    }
    cout<<"\n";
}


int main(){
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}