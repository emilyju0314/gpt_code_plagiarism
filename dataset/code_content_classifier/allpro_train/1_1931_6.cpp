#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int x,int y){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);
}

int main() {
    int ttt;
    cin>>ttt;
    while(ttt--){
        string s;
        cin>>s;
        int last1 = -1;
        int last0 = -1;
        long long ans =0ll;
        for(int i=0;i<s.size();i++){
            int c = s[i] - '0';
            if(c==0 || c==1){
                if((c^(i%2)) == 1){
                    last1 = i;
                }
                else{
                    last0 = i;
                }
            }
            int mn = min(last0,last1);
            //cout<<last0<<" "<<last1<<endl;
            ans += (long long)(i-mn);
        }
        cout<<ans<<endl;
    }
}
