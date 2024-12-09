#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    return b ? gcd(b, a%b) : a; 
}

int main(){
    long long a, b, ans=1, G;
    cin >> a >> b;
    G = gcd(a, b);
    for(long long i=2; i*i<=G; i++){
	if(G%i==0){
	    ans++;
	    while(G%i==0) G/=i; 
	}
    }

    if(G != 1)
	ans++;
    
    cout << ans << endl;
}

