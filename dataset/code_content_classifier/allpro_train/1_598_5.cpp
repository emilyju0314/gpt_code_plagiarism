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

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int> > d(h, vector<int>(w));
    for(int y=0; y<h; ++y){
        for(int x=0; x<w; ++x){
            cin >> d[y][x];
        }
    }

    vector<vector<int> > a(h, vector<int>(w, 0));
    for(int y=1; y<h-1; ++y){
        for(int x=1; x<w-1; ++x){
            a[y][x] = d[y-1][x-1];
            for(int i=0; i<9; ++i)
                d[y-1+i/3][x-1+i%3] -= a[y][x];
        }
    }

    vector<int> ay, ax;
    for(int y=1; y<h-1; ++y){
        for(int x=1; x<w-1; ++x){
            if(a[y][x] == 0)
                continue;

            int cnt = -a[y][x];
            for(int i=0; i<9; ++i)
                cnt += a[y-1+i/3][x-1+i%3];

            if(cnt < 2){
                ay.push_back(y);
                ax.push_back(x);
            }
        }
    }

    if(ay.size() == 1)
        cout << ay[0] << ' ' << ax[0] << ' ' << ay[0] << ' ' << ax[0] << endl;
    else if(10000 * ay[0] + ax[0] <= 10000 * ay[1] + ax[1])
        cout << ay[1] << ' ' << ax[1] << ' ' << ay[0] << ' ' << ax[0] << endl;
    else
        cout << ay[0] << ' ' << ax[0] << ' ' << ay[1] << ' ' << ax[1] << endl;

    return 0;
}