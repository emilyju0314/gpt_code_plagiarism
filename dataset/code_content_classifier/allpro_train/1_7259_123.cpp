#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n, x, y, b, p, res;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &x, &y, &b, &p);
        res = min(b*x+p*y, (max(5,b)*x+max(2,p)*y)*4/5);
        printf("%d\n", res);
    }
    return 0;
}

