#include <iostream>
using namespace std;

int main(void){
    int n;
    while(cin>>n,n){
        double s=0;
        int a[n];
        int ans=0;
        for(int i=0;i<n;i++) cin>>a[i],s+=a[i];
        s/=n;
        for(int i=0;i<n;i++){
            if(a[i]<=s) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
