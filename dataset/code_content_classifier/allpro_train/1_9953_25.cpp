#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int> > v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i].first;
    for(int i=0; i<n; ++i)
        cin >> v[i].second;
    sort(v.rbegin(), v.rend());

    int ans = 0;
    for(int j=0; j<(1<<n); ++j){
        bitset<15> bs(j);
        if(k < bs.count())
            continue;

        int rest = m;
        int cnt = 0;
        for(int i=0; i<n; ++i){
            if(bs[i]){
                int x = min(rest, v[i].second);
                cnt += v[i].first * x;
                rest -= x;
            }
        }
        ans = max(ans, cnt + rest);
    }
    cout << ans << endl;

    return 0;
}