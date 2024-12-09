#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;


int N, K, a[200000];
long long b[200001], c[200001];


int bit[1000010];
void add(int a, int w){
    for(int x = a; x <= N+1; x += x & -x) bit[x] += w;
}
int sum(int a){
    int ret = 0;
    for(int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}




int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    b[0] = 0 - 0*K;
    c[0] = 0;
    long long tmp[200001];
    tmp[0] = 0;
    for(int i = 1; i <= N; i++){
        b[i] = b[i-1] + a[i-1] - K;
        tmp[i] = b[i];
    }

    long long ans = 0;
    sort(tmp, tmp+N+1);
    for(int i = 0; i <= N; i++){
        c[i] = lower_bound(tmp, tmp+N+1, b[i]) - tmp;
        ans += sum(c[i]+1);
        add(c[i]+1, 1);
    }
    cout << ans << endl;

   

    
}