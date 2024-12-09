#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, xs, ys;
    string dir;
    cin >> n >> m >> xs >> ys >> dir;
    
    int paint = 0;
    
    // Initialize checkered with color of starting tile
    bool checkered = false;
    if ((xs + ys) % 2 == 0) checkered = true;
    
    // Calculate the amount of paint needed to obtain a checkered kitchen floor
    if (checkered){
        // If the floor is already checkered, no need to paint
        cout << 0 << endl;
    } else {
        if (dir == "UR" || dir == "DR"){
            paint = xs-1;
        } else {
            paint = m-xs;
        }
        
        if (dir == "UL" || dir == "UR"){
            paint += n-ys;
        } else {
            paint += ys-1;
        }
        
        if (paint % 2 == 0){
            cout << paint << endl;
        } else {
            cout << paint+1 << endl;
        }
    }
    
    return 0;
}