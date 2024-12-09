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
    for(;;){
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        vector<string> s1(n), s2(n);
        vector<int> t1(n), t2(n);
        map<string, int> index;
        for(int i=0; i<n; ++i){
            cin >> s1[i] >> t1[i] >> s2[i] >> t2[i];
            index[s1[i]] = i;
        }

        vector<int> sup(n);
        vector<vector<int> > edges(n);
        for(int i=0; i<n; ++i){
            sup[i] = index[s2[i]];
            if(s1[i] != s2[i])
                edges[index[s2[i]]].push_back(i);
        }

        int ret = 0;
        vector<bool> make(n, false);
        for(int i=0; i<n; ++i){
            if(make[i])
                continue;

            int j = i;
            vector<bool> check(n, false);
            while(!check[j]){
                check[j] = true;
                j = sup[j];
            }

            check.assign(n, false);
            int k = j;
            while(!check[j]){
                if(t1[j] - t2[j] < t1[k] - t2[k])
                    k = j;
                check[j] = true;
                j = sup[j];
            }

            ret += t1[k] - t2[k];
            queue<int> q;
            q.push(k);
            while(!q.empty()){
                int a = q.front();
                q.pop();
                ret += t2[a];
                make[a] = true;

                for(unsigned l=0; l<edges[a].size(); ++l){
                    int b = edges[a][l];
                    if(!make[b])
                        q.push(b);
                }
            }
        }

        cout << ret << endl;
    }
}