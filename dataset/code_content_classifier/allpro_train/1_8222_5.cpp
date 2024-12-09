#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

// 最大公約数
long long gcd(long long a, long long b){
    while(b != 0){
        long long tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    int n;
    long long m;
    cin >> n >> m;

    vector<long long> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];
    vector<double> p(n);
    for(int i=0; i<n; ++i){
        cin >> p[i];
        p[i] /= 100.0;
    }

    double ret = 0.0;
    for(int i=1; i<(1<<n); ++i){
        bitset<20> use(i);
        long long x = 1; // 選択された数字の最小公倍数
        for(int j=0; j<n; ++j){
            if(use[j]){
                x /= gcd(x, a[j]);
                if(LLONG_MAX / x < a[j]){
                    x = -1;
                    break;
                }
                x *= a[j];
            }
        }

        if(x == -1)
            continue;
        long long y = m / x; // xで割り切れる整数の個数

        double q = 1.0;
        for(int j=0; j<n; ++j){
            if(use[j])
                q *= p[j];
        }

        if(use.count() % 2 == 0)
            ret -= y * q;
        else
            ret += y * q;
    }

    printf("%.10f\n", ret);

    return 0;
}