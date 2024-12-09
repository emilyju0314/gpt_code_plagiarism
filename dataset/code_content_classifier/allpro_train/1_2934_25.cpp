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
    for(int d=1; ; ++d){
        int n, m;
        cin >> n >> m;
        if(n == 0)
            return 0;

        vector<int> curr(m+1, 0);
        curr[0] = n;

        for(int t=1; ; ++t){
            vector<int> next(m+1, 0);
            for(int i=0; i<m; ++i){
                next[0] += curr[i] / 2;
                next[i] += curr[i] % 2;
                next[i+1] += curr[i] / 2;
            }

            curr.swap(next);
            if(curr[m] > 0){
                cout << "Case " << d << ": " << t << endl;
                break;
            }
        }
    }
}