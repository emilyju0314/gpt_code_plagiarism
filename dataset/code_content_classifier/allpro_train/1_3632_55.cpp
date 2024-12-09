#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
 
typedef pair<int,int> pii;
 
inline int dist(const pii &p, const pii &q){
    return abs(p.first - q.first) + abs(p.second - q.second);
}
 
void input(int &w, int &h, vector<vector<int> > &v){
    string s;
    v.clear();
    v.resize(h);
    for(int i = 0; i < h; ++i){
        vector<int> &t = v[i];
        getline(cin, s);
        stringstream ss(s);
        while(ss >> s){
            if(s[0] == '.'){
                t.push_back(-1);
            }
            else if(s[0] == 'S'){
                t.push_back(-2);
            }
            else if(s[0] == 'G'){
                t.push_back(-3);
            }
            else{
                t.push_back(strtol(s.c_str(), 0, 10));
            }
        }
 
        if(t.size() != w){
            if(1 || i != 0){
                throw 0;
            }
            swap(h, w);
            v.resize(h);
        }
    }
}
 
int main(){
    const int INF = 1000000000;
    int w, h, x;
    char ch;
    vector<vector<int> > in;
    string str;
    while(getline(cin, str) && sscanf(str.c_str(), "%d%d", &w, &h) == 2 && w){
        map<int,vector<pii> > mp;
        map<int,vector<pii> >::iterator it1, it2;
        input(w, h, in);
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if(in[i][j] >= 0){
                    mp[in[i][j]].push_back(pii(i, j));
                }
                else if(in[i][j] == -2){
                    mp[0].push_back(pii(i, j));
                }
                else if(in[i][j] == -3){
                    mp[INF].push_back(pii(i, j));
                }
            }
        }
 
        vector<int> dp1(1, 0), dp2;
        it1 = it2 = mp.begin();
        while(++it2 != mp.end()){
            dp2.assign(it2->second.size(), INF);
            for(int i = 0; i < it1->second.size(); ++i){
                pii p1 = it1->second[i];
                for(int j = 0; j < it2->second.size(); ++j){
                    pii p2 = it2->second[j];
                    dp2[j] = min(dp2[j], dp1[i] + dist(p1, p2));
                }
            }
            dp1.swap(dp2);
            ++it1;
        }
        printf("%d\n", dp1[0]);
    }
}