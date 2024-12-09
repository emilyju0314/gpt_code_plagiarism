#include <iostream>
using namespace std;

int main() {
    int a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;

    int total_triangles = a1*a1 + a2*a2 + a3*a3 + a4*a4 + a5*a5 + a6*a6 + (a1 + a2 + a3 + a4 + a5 + a6) - min(a1, min(a2, min(a3, min(a4, min(a5, a6)))))*2;
    
    cout << total_triangles << endl;

    return 0;
}