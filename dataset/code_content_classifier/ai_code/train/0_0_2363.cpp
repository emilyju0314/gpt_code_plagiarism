#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x;
    cin >> x;
    
    vector<string> operations;
    
    int curr = x;
    operations.push_back(to_string(curr) + " + " + to_string(curr));
    
    curr = curr ^ (2 * x);
    operations.push_back(to_string(x) + " ^ " + to_string(2 * x));
    
    curr = curr + x;
    operations.push_back(to_string(curr) + " + " + to_string(x));
    
    curr = curr + x;
    operations.push_back(to_string(curr) + " + " + to_string(x));
    
    curr = curr ^ (curr - 1);
    operations.push_back(to_string(curr) + " ^ " + to_string(curr - 1));
    
    cout << operations.size() << endl;
    for (string op : operations) {
        cout << op << endl;
    }
    
    return 0;
}