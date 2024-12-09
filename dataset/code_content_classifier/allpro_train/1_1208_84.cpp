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

int pow2(int a){
    return a * a;
}

class Point
{
public:
    int x, y;
    Point(){
        x = y = 0;
    }
    Point(int x0, int y0){
        x = x0;
        y = y0;
    }
    bool graze(Point p, int r){
        return pow2(x-p.x) + pow2(y-p.y) <= pow2(4*r);
    }
};

int main()
{
    for(;;){
        int n, m, r;
        cin >> n >> m >> r;
        if(n == 0)
            return 0;

        vector<Point> a(n);
        for(int i=0; i<n; ++i)
            cin >> a[i].x >> a[i].y;

        vector<vector<vector<Point> > > b;
        b = vector<vector<vector<Point> > >(252, vector<vector<Point> >(252));
        for(int i=0; i<m; ++i){
            int x, y;
            cin >> x >> y;
            b[x/40+1][y/40+1].push_back(Point(x, y));
        }

        int ret = 0;
        for(int i=0; i<n; ++i){
            int x0 = a[i].x/40 + 1;
            int y0 = a[i].y/40 + 1;
            for(int x=x0-1; x<=x0+1; ++x){
                for(int y=y0-1; y<=y0+1; ++y){
                    for(unsigned j=0; j<b[x][y].size(); ++j){
                        if(a[i].graze(b[x][y][j], r))
                            ++ ret;
                    }
                }
            }
        }
        cout << ret << endl;
    }
}