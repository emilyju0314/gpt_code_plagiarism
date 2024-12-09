#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
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
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

/***************************************************************************************************/
// グレゴリオ暦の年月日から曜日を求める（ツェラーの公式）
// 関数値 : 0から6の値で、それぞれ土日月火水木金に対応
/***************************************************************************************************/
int zeller(long long y, int m, int d)
{
    if(m <= 2){
        -- y;
        m += 12;
    }
    long long j = y / 100;
    int k = y % 100;
    return (d + ((m+1)*26 / 10) + k + (k / 4) + (j / 4) + 5 * j) % 7;
}

long long solve(long long y1, int m1, int d1, long long y2, int m2, int d2)
{
    long long ans = 0;
    for(long long y=y1; y<=y2; ++y){
        for(int m=1; m<=12; ++m){
            if(make_tuple(y1, m1, d1) <= make_tuple(y, m, 13) && make_tuple(y, m, 13) <= make_tuple(y2, m2, d2) && zeller(y, m, 13) == 6)
                ++ ans;
        }
    }
    return ans;
}

int main()
{
    long long y1, y2;
    int m1, d1, m2, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    if(y2 - y1 < 1000){
        cout << solve(y1, m1, d1, y2, m2, d2) << endl;
        return 0;
    }

    long long y3 = (y1 + 400) / 400 * 400;
    long long y4 = (y2 - 1) / 400 * 400;
    long long ans = solve(1, 1, 1, 400, 12, 31) * ((y4 - y3) / 400);

    ans += solve(y1, m1, d1, y3 - 1, 12, 31);
    ans += solve(y4, 1, 1, y2, m2, d2);
    cout << ans << endl;

    return 0;
}
