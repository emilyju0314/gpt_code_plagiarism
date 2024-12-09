#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int red_sheets_needed = 2 * n;
    int green_sheets_needed = 5 * n;
    int blue_sheets_needed = 8 * n;

    int red_notebooks = ceil((double)red_sheets_needed / k);
    int green_notebooks = ceil((double)green_sheets_needed / k);
    int blue_notebooks = ceil((double)blue_sheets_needed / k);

    cout << red_notebooks + green_notebooks + blue_notebooks << endl;

    return 0;
}