#include <iostream>
using namespace std;

int N;
int h[200009];
int a[200009];

// BIT (1-indexed)
long long bit[200009];

void update(int a, long long k) {
    for(; a <= N; a += a & -a)
        if(bit[a] < k) bit[a] = k;
}

long long query(int a) {
    long long res = 0;
    for(; a > 0; a -= a & -a)
        if(res < bit[a]) res = bit[a];
    return res;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> h[i];
    for(int i = 0; i < N; i++)
        cin >> a[i];

    for(int i = 0; i < N; i++)
        update(h[i], query(h[i]) + a[i]);

    cout << query(N) << endl;
}