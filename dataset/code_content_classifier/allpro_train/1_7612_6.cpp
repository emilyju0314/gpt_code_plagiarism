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

const int INF = INT_MAX / 4;

int h, w;
vector<string> s;

int main()
{
    for(int d=1; ; ++d){
        cin >> w >> h;
        if(h == 0)
            return 0;

        if(w == 1)
            swap(h, w);

        s.assign(h, string(w, ' '));
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                cin >> s[i][j];
            }
        }

        if(h == 1 && w == 1){
            cout << "Case " << d << ": 0" << endl;
            continue;
        }

        vector<pair<int, int> > dp(1<<(2*w+2), make_pair(INF, -INF));
        for(int i=0; i<(1<<w); ++i){
            bitset<32> bs = i;
            int black = bs.count();
            bs <<= w;
            bs |= i;
            dp[bs.to_ulong()] = make_pair(black, black);
        }

        for(int y=0; y<h; ++y){
            for(int x=0; x<w; ++x){
                vector<pair<int, int> > next(1<<(2*w+2), make_pair(INF, -INF));
                for(int a=0; a<(1<<(2*w+2)); ++a){
                    if(dp[a].first == INF)
                        continue;

                    for(int b=0; b<2; ++b){
                        bitset<32> bs = a;
                        bs <<= 1;
                        bs |= b;
                        if(y == h-1 && (bs[0] ^ bs[w]))
                            continue;

                        bool ng = false;

                        if(x == 1){ // 左端
                            int black = 0;
                            for(int i=0; i<3; ++i){
                                for(int j=0; j<2; ++j){
                                    if(bs[i*w+j])
                                        black += j + 1;
                                }
                            }
                            if((black >= 5) ^ (s[y][x-1] == '#'))
                                ng = true;
                        }

                        if(x > 1){ // 中央
                            int black = 0;
                            for(int i=0; i<3; ++i){
                                for(int j=0; j<3; ++j){
                                    if(bs[i*w+j])
                                        ++ black;
                                }
                            }
                            if((black >= 5) ^ (s[y][x-1] == '#'))
                                ng = true;
                        }

                        if(x == w-1){ // 右端
                            int black = 0;
                            for(int i=0; i<3; ++i){
                                for(int j=0; j<2; ++j){
                                    if(bs[i*w+j])
                                        black += 2 - j;
                                }
                            }
                            if((black >= 5) ^ (s[y][x] == '#'))
                                ng = true;
                        }

                        if(!ng){
                            bs &= (1<<(2*w+2)) - 1;
                            if(y < h-1){
                                next[bs.to_ulong()].first = min(next[bs.to_ulong()].first, dp[a].first + b);
                                next[bs.to_ulong()].second = max(next[bs.to_ulong()].second, dp[a].second + b);
                            }else{
                                next[bs.to_ulong()].first = min(next[bs.to_ulong()].first, dp[a].first);
                                next[bs.to_ulong()].second = max(next[bs.to_ulong()].second, dp[a].second);
                            }
                        }
                    }
                }
                dp.swap(next);
            }
        }

        int minBlack = INF;
        int maxBlack = -INF;
        for(int i=0; i<(1<<(2*w+2)); ++i){
            minBlack = min(minBlack, dp[i].first);
            maxBlack = max(maxBlack, dp[i].second);
        }

        if(minBlack == INF)
            cout << "Case " << d << ": Impossible" << endl;
        else
            cout << "Case " << d << ": " << (maxBlack - minBlack) << endl;
    }
}