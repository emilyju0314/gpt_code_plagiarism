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

int main()
{
    int dNum;
    cin >> dNum;

    for(int d=1; d<=dNum; ++d){
        int h, w;
        cin >> w >> h;

        vector<vector<int> > r(h, vector<int>(w));
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                cin >> r[i][j];
            }
        }

        vector<int> dp(1<<w, -1);
        dp[0] = 0;
        for(int y=0; y<h; ++y){
            for(int x=0; x<w; ++x){
                vector<int> next(1<<w, -1);
                for(int i=0; i<(1<<w); ++i){
                    if(dp[i] == -1)
                        continue;

                    bitset<21> bs = i;
                    bs <<= 1;

                    if(!bs[w] && (x == 0 || !bs[1])){
                        bs &= (1<<w) - 1;
                        bs[0] = true;
                        next[bs.to_ulong()] = max(next[bs.to_ulong()], dp[i] + r[y][x]);
                        bs[0] = false;
                    }

                    bs &= (1<<w) - 1;
                    next[bs.to_ulong()] = max(next[bs.to_ulong()], dp[i]);
                }
                dp.swap(next);
            }
        }

        int ret = 0;
        for(int i=0; i<(1<<w); ++i)
            ret = max(ret, dp[i]);
        cout << "Case " << d << ": " << ret << endl;
    }

    return 0;
}