#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> sum, sumSquares, lazyAdd, lazyMul;
vector<int> arr;

void build(int node, int start, int end) {
    if (start == end) {
        sum[node] = arr[start];
        sumSquares[node] = arr[start] * arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        sum[node] = sum[2 * node] + sum[2 * node + 1];
        sumSquares[node] = sumSquares[2 * node] + sumSquares[2 * node + 1];
    }
}

void update(int node, int start, int end, int l, int r, long long add, long long mul) {
    if (lazyAdd[node] != 0 || lazyMul[node] != 1) {
        sum[node] = lazyMul[node] * sum[node] + (end - start + 1) * lazyAdd[node];
        sumSquares[node] = lazyMul[node] * lazyMul[node] * sumSquares[node] + 
                          2 * lazyMul[node] * lazyAdd[node] * sum[node] + 
                          (end - start + 1) * lazyAdd[node] * lazyAdd[node];
        if (start != end) {
            lazyAdd[2 * node] = lazyAdd[2 * node] * lazyMul[node] + lazyAdd[node];
            lazyMul[2 * node] = lazyMul[2 * node] * lazyMul[node];
            lazyAdd[2 * node + 1] = lazyAdd[2 * node + 1] * lazyMul[node] + lazyAdd[node];
            lazyMul[2 * node + 1] = lazyMul[2 * node + 1] * lazyMul[node];
        }
        lazyAdd[node] = 0;
        lazyMul[node] = 1;
    }

    if (start > r || end < l) return;
    if (start >= l && end <= r) {
        sum[node] = mul * sum[node] + (end - start + 1) * add;
        sumSquares[node] = mul * mul * sumSquares[node] + 
                          2 * mul * add * sum[node] + 
                          (end - start + 1) * add * add;
        if (start != end) {
            lazyAdd[2 * node] = lazyAdd[2 * node] * mul + add;
            lazyMul[2 * node] = lazyMul[2 * node] * mul;
            lazyAdd[2 * node + 1] = lazyAdd[2 * node + 1] * mul + add;
            lazyMul[2 * node + 1] = lazyMul[2 * node + 1] * mul;
        }
        return;
    }

    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, add, mul);
    update(2 * node + 1, mid + 1, end, l, r, add, mul);
    sum[node] = sum[2 * node] + sum[2 * node + 1];
    sumSquares[node] = sumSquares[2 * node] + sumSquares[2 * node + 1];
}

long long query(int node, int start, int end, int l, int r) {
    if (lazyAdd[node] != 0 || lazyMul[node] != 1) {
        sum[node] = lazyMul[node] * sum[node] + (end - start + 1) * lazyAdd[node];
        sumSquares[node] = lazyMul[node] * lazyMul[node] * sumSquares[node] + 
                          2 * lazyMul[node] * lazyAdd[node] * sum[node] + 
                          (end - start + 1) * lazyAdd[node] * lazyAdd[node];
        if (start != end) {
            lazyAdd[2 * node] = lazyAdd[2 * node] * lazyMul[node] + lazyAdd[node];
            lazyMul[2 * node] = lazyMul[2 * node] * lazyMul[node];
            lazyAdd[2 * node + 1] = lazyAdd[2 * node + 1] * lazyMul[node] + lazyAdd[node];
            lazyMul[2 * node + 1] = lazyMul[2 * node + 1] * lazyMul[node];
        }
        lazyAdd[node] = 0;
        lazyMul[node] = 1;
    }
    
    if (start > r || end < l) return 0;
    if (start >= l && end <= r) return sum[node];

    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    int n, q;
    cin >> n >> q;

    sum.resize(4 * n);
    sumSquares.resize(4 * n);
    lazyAdd.resize(4 * n, 0);
    lazyMul.resize(4 * n, 1);
    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            l1--; r1--; l2--; r2;
            update(1, 0, n - 1, l1, r1, 0, 0);
            update(1, 0, n - 1, l2, r2, 0, 0);
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << query(1, 0, n - 1, l, r) << endl;
        }
    }

    return 0;
}