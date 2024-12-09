#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2==1)
                cout<<a[i]<<" ";
        }
        for(int i=0;i<n;i++){
            if(a[i]%2==0){
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;

    }
    return 0;
}

