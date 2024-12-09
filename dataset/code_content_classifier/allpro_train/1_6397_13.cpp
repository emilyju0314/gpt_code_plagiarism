#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    ll T;
    cin >> T;
    vector<ll> beki3(32,1),sum3(32,1);
    for(int i=1;i<32;i++){
        beki3[i] = 3*beki3[i-1];
        sum3[i] = beki3[i]+sum3[i-1];
    }
    T++;
    ll x = 0,t = 1,cnt = 0;
    while(t<T){
        cnt++;
        if(t+sum3[x+1]<=T){
            x++;
            t += beki3[x];
        }else if(t+sum3[x]<=T){
            t += beki3[x];
        }else{
            x--;
            t += beki3[x];
        }
    }
    cout << cnt << endl;
}
