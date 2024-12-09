#include<bits/stdc++.h>
using namespace std;

void no() {
    cout<<"NO"<<endl;
    exit(0);
}

const int N = 1e5+7;
int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    long long sum = 0, B = 1LL*n*(n+1)/2;
    for (int i=1; i<=n; i++) {
        int x;
        cin>>x;
        sum += x;
        a[i] = x;
    }
    a[0] = a[n];

    if (sum%B)  no();
    long long K = sum/B;

    for (int i=1; i<=n; i++) {
        long long D = a[i] - a[i-1];
        if ((K-D)%n || K-D<0)    no();
    }
    cout<<"YES\n";
}
