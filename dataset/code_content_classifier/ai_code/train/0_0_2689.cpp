#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int min_isolated = max(0, n - 2*m);
    
    int max_isolated = n - m;

    cout << min_isolated << " " << max_isolated;

    return 0;
}