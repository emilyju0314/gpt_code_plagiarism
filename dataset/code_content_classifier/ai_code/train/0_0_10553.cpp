#include <iostream>
using namespace std;

int main() {
    int W, H, C;
    cin >> W >> H >> C;

    int total_plots = W * H;
    int minimum_cost = total_plots * C;

    cout << minimum_cost << endl;

    return 0;
}