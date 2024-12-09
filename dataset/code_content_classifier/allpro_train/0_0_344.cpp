#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    string n;
    cin >> n;

    // List of prime factors that are of form 4x + 3
    unordered_set<string> factors;

    // Function to perform operations using the provided calculator
    auto operate = [&](string op, string x, string y) {
        cout << op << " " << x << " " << y << endl;
        cout.flush();
        string result;
        cin >> result;
        return result;
    };

    // Check all possible prime factors
    for (int i = 2; i < 10; i++) {
        int curr = 4 * i + 3;
        string x = to_string(curr);
        
        // Check if the current number is a factor of n using calculator operations
        string res = operate("/", n, x);
        if (res != "-1") {
            factors.insert(x);
            n = res;
        }
    }

    // Print the result
    cout << "! " << factors.size();
    for (auto factor : factors) {
        cout << " " << factor;
    }
    cout << endl;

    return 0;
}