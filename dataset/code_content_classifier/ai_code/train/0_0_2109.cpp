#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    string protocol;
    string domain;
    string context;

    if (input.substr(0, 4) == "http") {
        protocol = "http";
        input = input.substr(4);
    } else {
        protocol = "ftp";
        input = input.substr(3);
    }

    int pos = 0;
    while (pos < input.size() && islower(input[pos])) {
        domain += input[pos];
        pos++;
    }

    if (pos < input.size()) {
        context = input.substr(pos);
    }

    cout << protocol << "://" << domain << ".ru";
    if (!context.empty()) {
        cout << "/" << context;
    }
    cout << endl;

    return 0;
}