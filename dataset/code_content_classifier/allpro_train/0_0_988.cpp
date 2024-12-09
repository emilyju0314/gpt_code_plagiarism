#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isKLucky(string ticket, int k) {
    for (int i = 1; i < ticket.size(); i++) {
        for (int j = i + 1; j < ticket.size(); j++) {
            for (int l = j + 1; l < ticket.size(); l++) {
                string expr = "(" + ticket.substr(0, i) + ")" + ticket.substr(i, j - i) + "(" + ticket.substr(j, l - j) + ")" + ticket.substr(l);
                int result = 0;
                if (sscanf(expr.c_str(), "%d", &result) != 1) {  
                    continue; 
                }
                if (result == k) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int k, m;
    cin >> k >> m;

    vector<string> output;

    for (int ticket = 0; output.size() < m; ticket++) {
        string ticketStr = to_string(ticket);
        while (ticketStr.size() < 8) {
            ticketStr = "0" + ticketStr;
        }

        if (isKLucky(ticketStr, k)) {
            output.push_back(ticketStr);
        }
    }

    for (string ticket : output) {
        cout << ticket << endl;
    }

    return 0;
}