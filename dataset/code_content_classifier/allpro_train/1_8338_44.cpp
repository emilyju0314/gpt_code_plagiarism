#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc,n,d;
    cin>>tc;
    while(tc--){
        cin>>n>>d;
        bool res=true,ans=false;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>d)
                res=false;
        }
        if(res)
            cout<<"YES"<<endl;
        else{
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(arr[i]+arr[j]<=d){
                        ans=true;
                        break;
                    }
                }
                if(ans)
                    break;
            }
            if(ans)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
