#include <iostream>
#include <string>

const int MOD = 1e9 + 7;

long long parseNumber(std::string& input, int& pos) {
    long long num = 0;

    while(pos < input.length() && isdigit(input[pos])) {
        num = (num * 10 + (input[pos] - '0')) % MOD;
        pos++;
    }

    return num;
}

long long parseTerm(std::string& input, int& pos);

long long parseExpression(std::string& input, int& pos) {
    long long result = parseTerm(input, pos);

    while(pos < input.length() && input[pos] == '+') {
        pos++;
        result += parseTerm(input, pos);
        result %= MOD;
    }

    return result;
}

long long parseTerm(std::string& input, int& pos) {
    long long result = 1;

    if(input[pos] == '(') {
        pos++;

        int repeat = parseNumber(input, pos);
        pos++;

        long long innerResult = parseExpression(input, pos);

        for(int i = 0; i < repeat; i++) {
            result *= innerResult;
            result %= MOD;
        }
    } else if(input[pos] == '-') {
        pos++;

        long long start = parseNumber(input, pos);
        pos++;

        long long end = parseNumber(input, pos);

        for(long long i = start; i <= end; i++) {
            result = (result * i) % MOD;
        }
    } else {
        result = parseNumber(input, pos);
    }

    return result;
}

int main() {
    std::string input;
    std::cin >> input;

    int pos = 0;
    long long result = parseExpression(input, pos);

    std::cout << result << "\n";

    return 0;
}