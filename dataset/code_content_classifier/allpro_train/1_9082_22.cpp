#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int N;
    while(cin >> N && N >= 0){
        bool v_wall[40][40] = {}; // tate
        bool h_wall[40][40] = {}; // yoko
        REP(i, N){
            string d;
            int x, y;
            cin >> d >> x >> y;
            if(d[0] == 'x'){
                for(int dx = 0; dx < 4; dx++){
                    h_wall[4 * y][4 * x + dx] = true;
                }
            }else{
                for(int dy = 0; dy < 4; dy++){
                    v_wall[4 * y + dy][4 * x] = true;
                }
            }
        }
        int x = 3;
        int y = 1;
        int dx = 1;
        int dy = 1;
        while(true){
            x += dx;
            y += dy;
            if(h_wall[y][x]) dy *= -1;
            if(v_wall[y][x]) dx *= -1;
            if(!h_wall[y][x] && !v_wall[y][x]){
                if(x == 0 || x == 8 * 4 || y == 0 || y == 8 * 4){
                    break;
                }
                if(x == 3 && y == 1){
                    break;
                }
            }
        }
        cout << x * 25 << " " << y * 25 << endl;
    }
    return 0;
}