#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, p = -1;
ll r;

int main(){
    scanf("%d", &n);
    for(int x; n--; ){
        scanf("%d", &x);
        if(p + 1 == x) r++;
        else if(x <= p) r += x;
        else { puts("-1"); return 0; }
        p = x;
    }
    printf("%lld\n", r - 1);
}