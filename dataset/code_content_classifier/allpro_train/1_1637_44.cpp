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
        int n, m;
        cin >> n >> m;
        if(n == 0)
            return 0;

        map<string, vector<int> > name;
        int prev = -1;
        vector<int> tmp;
        cin.ignore();
        for(int i=0; i<n; ++i){
            string s;
            getline(cin, s);
            int j = s.find_first_not_of(' ');
            s = s.substr(j);
            if(j < prev){
                while(j < prev){
                    tmp.pop_back();
                    -- prev;
                }
                ++ tmp.back();
            }else if(j == prev){
                ++ tmp.back();
            }else{
                tmp.push_back(0);
                ++ prev;
            }
            name.insert(make_pair(s, tmp));
        }

        for(int i=0; i<m; ++i){
            string x0, y0, s;
            cin >> x0 >> s >> s >> s >> y0 >> y0;
            y0.resize(y0.size() - 1);

            vector<int> x = name[x0];
            vector<int> y = name[y0];

            if(s == "child" || s == "parent"){
                if(s == "parent")
                    swap(x, y);
                x.resize(x.size() - 1);
            }else if(s == "sibling"){
                x.resize(x.size() - 1);
                y.resize(y.size() - 1);
            }else{
                if(s == "ancestor")
                    swap(x, y);
                if(x.size() > y.size())
                    x.resize(y.size());
            }

            if(x == y)
                cout << "True" << endl;
            else
                cout << "False" << endl;
        }

        cout << endl;
    }
}