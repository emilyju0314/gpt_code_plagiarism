#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<string, int> government;
    unordered_map<string, bool> active;
    string citizen[k];

    for(int i = 0; i < k; i++) {
        cin >> citizen[i];
        government[citizen[i]] = 0;
        active[citizen[i]] = false;
    }

    for(int i = 0; i < n; i++) {
        char op;
        string arg;
        cin >> op >> arg;

        if(op == '+') {
            active[arg] = true;
        } else if(op == '-') {
            active[arg] = false;
        } else if(op == '?') {
            int politicization = 0;
            for(auto it : government) {
                size_t pos = 0;
                while((pos = arg.find(it.first, pos)) != string::npos) {
                    politicization++;
                    pos++;
                }
            }
            cout << politicization << endl;
        }
    }

    return 0;
}