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

int n, m, p;
vector<string> name;
vector<vector<int> > d;
map<string, string> variable;
bool error;

vector<int> solve(const string& s, int a, int b)
{
    int brackets = 0;
    for(int i=b-1; i>=a; --i){
        if(s[i] == '(')
            ++ brackets;
        else if(s[i] == ')')
            -- brackets;
        else if(brackets == 0 && (s[i] == '+' || s[i] == '-')){
            vector<int> x = solve(s, a, i);
            vector<int> y = solve(s, i+1, b);
            if(x != y)
                error = true;
            return x;
        }
    }

    for(int i=b-1; i>=a; --i){
        if(s[i] == '(')
            ++ brackets;
        else if(s[i] == ')')
            -- brackets;
        else if(brackets == 0 && (s[i] == '*' || s[i] == '/')){
            vector<int> x = solve(s, a, i);
            vector<int> y = solve(s, i+1, b);
            if(s[i] == '*'){
                for(int j=0; j<n; ++j)
                    x[j] += y[j];
            }else{
                for(int j=0; j<n; ++j)
                    x[j] -= y[j];
            }
            return x;
        }
    }

    if(s[a] == '(')
        return solve(s, a+1, b-1);

    string t = s.substr(a, b-a);
    return d[find(name.begin(), name.end(), variable[t]) - name.begin()];
}

int main()
{
    for(;;){
        cin >> n >> m >> p;
        if(n == 0)
            return 0;

        name.resize(m);
        d.assign(m, vector<int>(n));
        for(int i=0; i<m; ++i){
            cin >> name[i];
            for(int j=0; j<n; ++j)
                cin >> d[i][j];
        }

        string formula;
        cin >> formula;

        variable.clear();
        for(int i=0; i<p; ++i){
            string s, t;
            cin >> s >> t;
            variable[s] = t;
        }

        error = false;
        vector<int> ret = solve(formula, 0, formula.size());
        if(error)
            cout << "error" << endl;
        else{
            int j = -1;
            for(int i=0; i<m; ++i){
                if(ret == d[i])
                    j = i;
            }
            if(j == -1)
                cout << "undefined" << endl;
            else
                cout << name[j] << endl;
        }
    }
}