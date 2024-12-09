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
    int dy[] = {1, 1, 0, 1};
    int dx[] = {0, 1, 1, -1};

    for(;;){
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        vector<string> s(n+2);
        s[0] = s[n+1] = string(n+2, '0');
        for(int i=1; i<=n; ++i){
            cin >> s[i];
            s[i] = '0' + s[i] + '0';
        }

        int ret = 0;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                for(int k=0; k<4; ++k){
                    int y = i;
                    int x = j;
                    if(s[y-dy[k]][x-dx[k]] == '1')
                        continue;
                    int num = 0;
                    while(s[y][x] == '1'){
                        ++ num;
                        y += dy[k];
                        x += dx[k];
                    }
                    ret = max(ret, num);
                }
            }
        }

        cout << ret << endl;
    }
}