#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    cout << x << endl;

    vector<int> nums = {x, y, z};
    
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    
    cout << endl;

    char c;
    int a, b;
    cin >> c >> a >> b;

    cout << c << " " << a << endl;
    cout << c << " " << b << endl;

    return 0;
}