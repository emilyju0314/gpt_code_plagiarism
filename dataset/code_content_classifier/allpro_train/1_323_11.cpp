#include<iostream>
using namespace std;
#define int long long
int gcd(int a, int b) {if(!b)return a;return gcd(b, a%b);}
signed main(){int n, x;cin >> n >> x;cout << 3 * (n - gcd(n, x))<< endl;}