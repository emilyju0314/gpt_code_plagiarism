#include <bits/stdc++.h>
using namespace std;

long long n;
int main(){
    cin >> n;
    for(long long i = sqrt(n+10000LL); i >= 1; i--){
        if(i*i <= n && n % i == 0){ cout << i+n/i-2; return 0; }
    }
}
