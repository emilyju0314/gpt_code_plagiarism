#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    
    int minFlowers = min(min(r/3, g/3), b/3);
    
    int maxBouquets = minFlowers * 3;
    
    r -= minBouquets;
    g -= minBouquets;
    b -= minBouquets;
    
    if(r >= 1 && g >= 1 && b >= 1) {
        maxBouquets += 1;
    }
    
    cout << maxBouquets << endl;
    
    return 0;
}