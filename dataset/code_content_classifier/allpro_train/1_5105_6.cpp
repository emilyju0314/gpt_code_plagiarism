#include<iostream>
#include<cassert>
#include<vector>
#include<map>
#include<string>

using namespace std;

typedef long long ll;

ll binary_to_ll(string s, int n){
    ll a = 0LL;
    for(int j=0;j<n;j++) a |= (ll(s[j] == '1') << (n-1-j));
    return a;
}

int get_lsb(ll a, int n){
    int lsb = 0;
    while(lsb < n && ((a >> lsb) & 1LL) == 0LL) lsb++;
    return lsb;
}

void up_lsb(ll *a, int *lsb){
    if((*a >> (*lsb+1)) & 1LL){
        // 11→10
        *a ^= (1LL << (*lsb));
    }else{
        // 01→10
        *a ^= (3LL << (*lsb));
    }
    
    (*lsb)++;
}

int solve(string s, string t){
    int n = int(s.length());
    ll a = binary_to_ll(s, n), b = binary_to_ll(t, n);
    int lsba = get_lsb(a, n), lsbb = get_lsb(b, n);
    int d = 0;
    while(a != b){
        if(lsba < lsbb){
            up_lsb(&a, &lsba);
        }else{
            up_lsb(&b, &lsbb);
        }
        d++;
    }
    return d;
}

int main(){
    int n;
    cin >> n;
    string s,t;
    for(int i=0;i<n;i++){
        cin >> s >> t;
        cout << solve(s,t) << endl;
    }
}
