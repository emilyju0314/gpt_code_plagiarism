#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

pair<long long, long long> simplifyFraction(long long numerator, long long denominator) {
    if (denominator == 0) {
        return make_pair(0, 0);
    }
    long long gcd = __gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    return make_pair(numerator, denominator);
}

string convertToFraction(string str) {
    long long integerPart = stoi(str.substr(0, str.find('.')));
    long long decimalPart = stoi(str.substr(str.find('.') + 1, str.size() - str.find('.') - 1));
    
    string cycleStr;
    if (str.find('(') != string::npos) {
        cycleStr = str.substr(str.find('(') + 1, str.find(')') - str.find('(') - 1);
    }
    
    long long nonRecurringPart = integerPart * pow(10, cycleStr.size());
    long long cyclePart = decimalPart - nonRecurringPart;
    cyclePart *= pow(10, cycleStr.size());
    nonRecurringPart += cyclePart;
    
    long long denominator = pow(10, decimalPart.to_string().size()) - pow(10, nonRecurringPart.to_string().size());
    long long numerator = nonRecurringPart;
    
    return to_string(simplifyFraction(numerator, denominator).first) + "/" + to_string(simplifyFraction(numerator, denominator).second);
}

int main() {
    string input;
    cin >> input;
    
    cout << convertToFraction(input) << endl;
    
    return 0;
}