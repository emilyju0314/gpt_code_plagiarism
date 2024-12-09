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

int n;
vector<vector<int> > to;

void solve(vector<string> start, map<vector<string>, int>& history)
{
    queue<vector<string> > q1;
    q1.push(start);
    history[start] = 0;

    for(int a=1; a<=3; ++a){
        queue<vector<string> > q2;
        while(!q1.empty()){
            vector<string> s = q1.front();
            q1.pop();

            for(int i=0; i<n*2; ++i){
                for(unsigned j=0; j<to[i].size(); ++j){
                    vector<string> t = s;
                    while(!t[i/2].empty()){
                        char c;
                        if(i % 2 == 0){
                            c = t[i/2][0];
                            t[i/2] = t[i/2].substr(1);
                        }else{
                            c = t[i/2][t[i/2].size()-1];
                            t[i/2] = t[i/2].substr(0, t[i/2].size()-1);
                        }

                        if(to[i][j] % 2 == 0){
                            t[to[i][j]/2] = c + t[to[i][j]/2];
                        }else{
                            t[to[i][j]/2] += c;
                        }

                        if(history.find(t) == history.end()){
                            q2.push(t);
                            history[t] = a;
                        }
                    }
                }
            }
        }
        q1 = q2;
    }
}

int main()
{
    for(;;){
        int m;
        cin >> n >> m;
        if(n == 0)
            return 0;

        to.assign(2*n, vector<int>());
        for(int i=0; i<m; ++i){
            string s, t;
            cin >> s >> t;
            int a = (s[0] - '0') * 2;
            int b = (t[0] - '0') * 2;
            if(s[1] == 'E')
                ++ a;
            if(t[1] == 'E')
                ++ b;
            to[a].push_back(b);
            to[b].push_back(a);
        }

        vector<string> s(n), t(n);
        for(int i=0; i<n; ++i){
            cin >> s[i];
            if(s[i] == "-")
                s[i] = "";
        }
        for(int i=0; i<n; ++i){
            cin >> t[i];
            if(t[i] == "-")
                t[i] = "";
        }

        map<vector<string>, int> history1, history2;
        solve(t, history2);
        solve(s, history1);

        int ret = INT_MAX;
        map<vector<string>, int>::iterator it1, it2;
        it1 = history1.begin();
        it2 = history2.begin();
        while(it1 != history1.end() && it2 != history2.end()){
            if(it1->first == it2->first)
                ret = min(ret, it1->second + it2->second);
            if(it1->first < it2->first)
                ++ it1;
            else
                ++ it2;
        }

        cout << ret << endl;
    }
}