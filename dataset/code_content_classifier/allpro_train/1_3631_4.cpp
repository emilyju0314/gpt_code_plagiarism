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

const double INF = DBL_MAX / 1000;

int main()
{
    for(int d=1; ; ++d){
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        vector<double> x(2*n), y(2*n);
        for(int i=0; i<2*n; ++i)
            cin >> x[i] >> y[i];

        vector<vector<double> > len(1<<n, vector<double>(2*n, INF));
        for(int i=0; i<2*n; ++i){
            bitset<14> bs = 1 << (i / 2);
            len[bs.to_ulong()][i] = 0.0;
        }

        for(int i=0; i<(1<<n); ++i){
            bitset<14> bs = i;
            for(int j=0; j<2*n; ++j){
                if(!bs[j/2])
                    continue;

                for(int k=0; k<2*n; ++k){
                    if(bs[k/2])
                        continue;

                    bs[k/2] = true;
                    len[bs.to_ulong()][k^1] = min(len[bs.to_ulong()][k^1], len[i][j] + sqrt(pow(x[j] - x[k], 2) + pow(y[j] - y[k], 2)));
                    bs[k/2] = false;
                }
            }
        }

        double ret = INF;
        for(int i=0; i<2*n; ++i)
            ret = min(ret, len[(1<<n)-1][i]);

        for(int i=0; i<n; ++i)
            ret += sqrt(pow(x[2*i] - x[2*i+1], 2) + pow(y[2*i] - y[2*i+1], 2));

        printf("Case %d: %.5f\n", d, ret);
    }
}