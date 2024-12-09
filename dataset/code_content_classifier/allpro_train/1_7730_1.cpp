#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int n, k;
    cin >> n >> k;
    vector< int > a(n), b(n+1);
    for(int i = 0; i < n; i++) cin >> a[i];

    auto f = [&](int m)->bool{
        b[0] = 0;
        for(int i = 0; i < n; i++) b[i+1] = b[i] + (a[i] >= m ? 1 : 0);
        int mn[2] = {1000000, 1000000};
        for(int i = k; i <= n; i++){
            int j = i-k;
            mn[j%2] = min(mn[j%2], b[j] * 2 - j);
            if(b[i]*2 - i >= mn[i%2] + 2) return true;
            if(b[i]*2 - i >= mn[(i+1)%2] + 1) return true;
        }
        return false;
    };

    int ok = 1, ng = n+1;
    while(ok + 1 < ng){
        int m = (ok + ng) / 2;
        if(f(m)) ok = m;
        else ng = m;
    }
    cout << ok << endl;
}
