#include<bits/stdc++.h>
using namespace std;

long long n, k, vt, x, mx = -1e9, mn = 1e9, vtmx, vtmn;
vector<long long> a;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x, a.push_back(x);
        if (mx < x) mx = x, vtmx = i;
        if (mn > x) mn = x, vtmn = i;
    } 
    if (mx + mn > 0){
        vt = vtmx;
        cout << 2*n - 1 << endl;
        for (int i = 1; i <= n; i++) {
            cout << vt << " " << i << endl;
        }
        for (int i = 1; i < n; i++) {
            cout << i <<" " << i+1 << endl;
        }
    }
    else{
        vt = vtmn;
        cout << 2*n - 1 << endl;
        for (int i = 1; i <= n; i++){
            cout << vt << " " << i << endl;
        }
        for (int i = n; i > 1; i--){
            cout << i << " " << i-1 << endl;
        }
    }
}