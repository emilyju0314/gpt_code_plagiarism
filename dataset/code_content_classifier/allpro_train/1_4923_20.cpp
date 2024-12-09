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
    for(;;){
        int n, t;
        cin >> n >> t;
        if(n == 0)
            return 0;

        vector<vector<int> > time(n);
        for(int i=0; i<n; ++i){
            for(;;){
                int a;
                cin >> a;
                if(a == 0)
                    break;
                time[i].push_back(a);
            }
        }

        int ret = 0;
        vector<int> pos(n, 0);
        vector<int> pass(n, 0);
        queue<int> line;
        while(--t >= 0){
            bool end = false;
            for(int i=0; i<n; ++i){
                if(pos[i] % 2 == 0){
                    ++ pass[i];
                    if(pass[i] == time[i][pos[i]]){
                        pass[i] = -1;
                        ++ pos[i];
                    }
                }else{
                    if(pass[i] == -1){
                        pass[i] = 0;
                        line.push(i);
                    }
                    if(line.front() == i)
                        ++ pass[i];
                    else
                        ++ ret;

                    if(pass[i] == time[i][pos[i]]){
                        end = true;
                        pass[i] = 0;
                        ++ pos[i];
                        if(pos[i] == (int)time[i].size())
                            pos[i] = 0;
                    }
                }
            }
            if(end)
                line.pop();
        }

        cout << ret << endl;
    }
}