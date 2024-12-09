#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)

int code[8][3] = {
    {0, 0, 0},
    {0, 0, 255},
    {0, 255, 0},
    {0, 255, 255},
    {255, 0, 0},
    {255, 0, 255},
    {255, 255, 0},
    {255, 255, 255}
};
string name[8] = {"black",
                  "blue",
                  "lime",
                  "aqua",
                  "red",
                  "fuchsia",
                  "yellow",
                  "white"
};

int convert(string s){
    int d;
    sscanf(s.c_str(), "%x", &d);
    return d;
}

int main(){
    string line;
    while(cin >> line && line[0] != '0'){
        int r = convert(line.substr(1, 2));
        int g = convert(line.substr(3, 2));
        int b = convert(line.substr(5, 2));
        int ans_dist = 1e9;
        string ans = "--";
        rep(i,8){
            auto c = code[i];
            int d = 0;
            d += (r-c[0]) * (r-c[0]);
            d += (g-c[1]) * (g-c[1]);
            d += (b-c[2]) * (b-c[2]);
            if(d < ans_dist){
                ans_dist = d;
                ans = name[i];
            }
        }
        cout << ans << endl;
    }
}