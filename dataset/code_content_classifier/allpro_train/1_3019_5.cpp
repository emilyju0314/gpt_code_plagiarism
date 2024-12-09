#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

int BobEven(int n, int *A) {
    int M = n / 2;
    int res = INT_MAX;
    for(int i = 1; i <= M; i++)
        res = min(res, A[M+i]-A[i]);
    return res;
}

int AliceOdd(int n, int *A) {
    int M = n / 2;
    for(int i = M + 1; i < n; i++) A[i] = A[i + 1];
    return BobEven(n - 1, A);
}
bool check(int n, int *A, int M) {
    int cnt = 0;
    int last = 1;
    for(int i = 1; i <= n; i++)
        if(A[i] - A[last] > M)
            cnt++, last = i;
    return cnt >= n / 2;
}
int AliceEven(int n, int *A) {
    int L = 1, H = A[n] - A[1];
    while(L<H) {
        int M = L + H >> 1;
        if(check(n, A, M))
            L = M+1;
        else H = M;
    }
    return L;
}
int BobOdd(int n, int *A) {
    return min(AliceEven(n - 1, A), AliceEven(n - 1, A + 1));
}

int n, A[MAXN + 10];

int main() {

    string name;
    cin >> n >> name;
    for(int i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    if(name == "Alice") {
        if(n & 1) cout << AliceOdd(n, A) << endl;
        else cout << AliceEven(n, A) << endl;
    }
    else {
        if(n & 1) cout << BobOdd(n, A) << endl;
        else cout << BobEven(n, A) << endl;
    }

    return 0;
}