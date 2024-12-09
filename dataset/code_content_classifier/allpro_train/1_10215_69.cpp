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

class Edge
{
public:
    int to, cost;
    Edge(){};
    Edge(int to0, int cost0){to = to0; cost = cost0;}
};

vector<vector<Edge> > edges;
vector<bool> check;

bool checkNg(int s, int t, int rest)
{
    check[s] = true;
    if(s == t)
        return rest != 0;

    for(unsigned i=0; i<edges[s].size(); ++i){
        int next = edges[s][i].to;
        if(check[next])
            continue;
        if(checkNg(next, t, rest - edges[s][i].cost))
            return true;
    }
    return false;
}

int main()
{
    for(;;){
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        bool ok = true;
        map<string, int> index;
        edges.assign(n*2, vector<Edge>(0));
        for(int i=0; i<n; ++i){
            string s1, s2;
            int x;
            char c;
            cin >> c >> s1 >> c >> c >> c >> c >> x >> s2;

            int k1, k2;
            if(index.find(s1) == index.end()){
                k1 = index.size();
                index[s1] = k1;
            }else{
                k1 = index[s1];
            }
            if(index.find(s2) == index.end()){
                k2 = index.size();
                index[s2] = k2;
            }else{
                k2 = index[s2];
            }

            check.assign(2*n, false);
            if(checkNg(k1, k2, x))
                ok = false;

            edges[k1].push_back(Edge(k2, x));
            edges[k2].push_back(Edge(k1, -x));
        }

        if(ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}