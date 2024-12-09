#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

using namespace std;
char res[1000][1000];

int main() {
    int h, w, d;
    scanf("%d %d %d", &h, &w, &d);
    int l = 2*d;
    fo(y,0,h) fo(x,0,w) {
        int a = ((y-x)%l+l)%l;
        a /= d;
        int b = ((y+x)%l+l)%l;
        b /= d;
        int s = (a<<1)|b;
        res[y][x] = "RGBY"[s];
    }
    fo(y,0,h) printf("%s\n", res[y]);
}
