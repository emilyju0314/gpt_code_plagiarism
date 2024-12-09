#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function to convert prefixed notation to exponential notation
void convertToExponential(double num, string prefix, string unit) {
    int power;
    if (prefix == "yotta") power = 24;
    else if (prefix == "zetta") power = 21;
    else if (prefix == "exa") power = 18;
    else if (prefix == "peta") power = 15;
    else if (prefix == "tera") power = 12;
    else if (prefix == "giga") power = 9;
    else if (prefix == "mega") power = 6;
    else if (prefix == "kilo") power = 3;
    else if (prefix == "hecto") power = 2;
    else if (prefix == "deca") power = 1;
    else if (prefix == "deci") power = -1;
    else if (prefix == "centi") power = -2;
    else if (prefix == "milli") power = -3;
    else if (prefix == "micro") power = -6;
    else if (prefix == "nano") power = -9;
    else if (prefix == "pico") power = -12;
    else if (prefix == "femto") power = -15;
    else if (prefix == "ato") power = -18;
    else if (prefix == "zepto") power = -21;
    else if (prefix == "yocto") power = -24;
    else power = 0; // No prefix

    double exponent = log10(num) + power;
    cout << num << " * 10^" << exponent << " " << unit << endl;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        double num;
        string prefix, unit;

        cin >> num >> prefix;
        getline(cin >> ws, unit); // Read the remaining string including spaces

        convertToExponential(num, prefix, unit);
    }

    return 0;
}