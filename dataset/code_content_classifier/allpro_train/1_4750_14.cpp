#include <cstdio>
#include <algorithm>
using namespace std;
int arr[101];

int main()  {
    int N, res = 0, idx;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    sort(arr, arr+N);
    for (int i = N; i > 0; i--) {
        idx = int(lower_bound(arr, arr+N, i) - arr);
        if (N -idx >= i) res = max(res, i);
    }
    printf("%d\n", res);

    return 0;
}

