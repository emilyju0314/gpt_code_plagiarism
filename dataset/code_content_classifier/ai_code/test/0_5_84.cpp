#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int c(int l, int r) {
    int count = 0;
    for(int i=l; i<=r; i++) {
        for(int j=i; j<=r; j++) {
            if(gcd(i, j) >= l)
                count++;
        }
    }
    return count;
}

int f(int n, int k) {
    vector<int> x(k+2, 0);
    x[k+1] = n;
    int sum = 0;
    for(int i=1; i<=k+1; i++) {
        sum += c(x[i-1]+1, x[i]);
    }
    return sum;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << f(n, k) << endl;
    }

    return 0;
}