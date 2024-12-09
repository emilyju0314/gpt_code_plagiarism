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

const int INF = INT_MAX / 2;

int main()
{
    for(;;){
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        bitset<16> initial, final;
        for(int i=0; i<n; ++i){
            char c;
            cin >> c;
            initial[i] = (c == 'B');
        }
        for(int i=0; i<n; ++i){
            char c;
            cin >> c;
            final[i] = (c == 'B');
        }

        vector<vector<int> > memo(1<<n, vector<int>(n, INF));
        multimap<int, pair<bitset<16>, int> > mm;
        for(int i=0; i<n; ++i){
            memo[initial.to_ulong()][i] = 0;
            mm.insert(make_pair(0, make_pair(initial, i)));
        }

        for(;;){
            int cost = mm.begin()->first;
            bitset<16> bs = mm.begin()->second.first;
            int pos = mm.begin()->second.second;
            mm.erase(mm.begin());
            if(cost > memo[bs.to_ulong()][pos])
                continue;

            if(bs == final){
                cout << cost << endl;
                break;
            }

            for(int i=0; i<n; ++i){
                for(int j=0; j<n; ++j){
                    if(!(bs[i] ^ bs[j]))
                        continue;

                    int cost2 = cost + abs(pos - i) + abs(i - j);
                    bitset<16> bs2 = bs;
                    bs2[i] = !bs2[i];
                    bs2[j] = !bs2[j];
                    if(cost2 < memo[bs2.to_ulong()][j]){
                        memo[bs2.to_ulong()][j] = cost2;
                        mm.insert(make_pair(cost2, make_pair(bs2, j)));
                    }
                }
            }
        }
    }
}